Option Explicit
Public firm_array As Variant 'двумерный массив из фирм
Public new_sheet_report_pattern As String 'query будет объявлен как static


Sub main()
    Application.ScreenUpdating = False 'отключаем обновление экрана
    
    Dim get_user_confirm_flag As Boolean
    Dim get_firm_array_flag As Boolean
    Dim get_db_query_flag As Boolean
    Dim queryFirmExists_flag As Boolean
    Dim clear_results_flag As Boolean
    Dim filter_table_flag As Boolean
    Dim copy_result_flag As Boolean
    
    get_user_confirm_flag = get_user_confirm() 'получаем подтверждение пользователя
        If get_user_confirm_flag Then _
    get_firm_array_flag = get_firm_array() Else Exit Sub 'создаем массив уникальных фирм
        If get_firm_array_flag Then _
    get_db_query_flag = get_db_query() Else Exit Sub 'проверяем существование фирмы в массиве
        If get_db_query_flag Then _
    filter_table_flag = filter_table() Else Exit Sub 'фильтруем таблицу
        If filter_table_flag Then _
    copy_result_flag = copy_result() Else Exit Sub   'копируем результаты на другой лист
        If copy_result_flag Then
    MsgBox "Готово!", vbInformation, "Отбор данных"
        Else
            MsgBox "Ошибка!", vbInformation, "Отбор данных"
            Application.ScreenUpdating = True
        End If
    Application.ScreenUpdating = True 'включаем обновление экрана обратно
End Sub


Public Function get_user_confirm() As Boolean
    Dim button As Byte

    button = MsgBox("Фильтровать?", _
    vbOKCancel + vbMsgBoxHelpButton + vbQuestion + vbDefaultButton2, _
    "Отбор данных")
    
    If button = vbOK Then get_user_confirm = True
End Function


Public Function get_db_query() As Boolean
    Static query As String 'запрос пользователя
    
    Dim input_string As String
    Dim doContinue As Boolean
    doContinue = True 'флаг продолжения цикла
    
    Do While doContinue
        input_string = InputBox("Введите фирму: ", "Отбор данных", query)
        If StrPtr(input_string) = 0 Then 'для корректной работы vbCancel/отмены
            doContinue = False
            Exit Function
        Else
            query = input_string 'иначе работаем с запросом
            Select Case query
                Case vbNullString
                    MsgBox "Введите название фирмы!", vbCritical, "Отбор данных"
                    doContinue = True
                Case Else
                    query = LCase(query) 'лоукейсим запрос
                    If queryFirmExists(query) Then
                        doContinue = False
                        Range("crit_firm").Value = query 'задаем значение столбца фильтра
                        new_sheet_report_pattern = query 'задаем начало имени нового листа, если оно понадобится
                        get_db_query = True
                    Else: MsgBox "Уточните название фирмы", vbCritical, "Отбор данных"
                    End If
            End Select
        End If
    Loop
End Function


Public Function get_firm_array()
    'вставляем новый лист для вывода результатов excel-removeDuplicates
    ActiveWorkbook.Sheets.Add.Name = "sheetFirmArray"
    'копируем столбец фирм на этот лист,
    Range(Worksheets("Склад").Range("E4"), _
    Worksheets("Склад").Range("E4").End(xlDown)). _
    Copy Destination:=Worksheets("sheetFirmArray").Cells(1, 1)
        
    Application.CutCopyMode = False
    'средствами excel убираем дубликаты
    Range(Worksheets("sheetFirmArray").Cells(1, 1), _
        Worksheets("sheetFirmArray").Cells(1, 1).End(xlDown)).RemoveDuplicates _
        Columns:=1, Header:=xlYes
    Worksheets("sheetFirmArray").Cells(1, 1).EntireRow.Delete
    'из диапазона результирующих ячеек формируем массив
    firm_array = Range(Worksheets("sheetFirmArray").Cells(1, 1), _
        Worksheets("sheetFirmArray").Cells(1, 1).End(xlDown)).Value
    '============================================================================
    'удаляем страницу после создания массива
    Application.DisplayAlerts = False
    ActiveWorkbook.Worksheets("sheetFirmArray").Delete
    Application.DisplayAlerts = True
    '============================================================================
    get_firm_array = True
End Function


Public Function queryFirmExists(query_arg)
    Dim element As Variant
    queryFirmExists = False
    
    For Each element In firm_array
        If (query_arg = LCase(element)) Then
            queryFirmExists = True
            Exit Function
        End If
    Next
End Function


Public Function clear_results(arg_sheet As String) As Boolean
     Select Case arg_sheet
        'удаляем старые результаты фильтра
        Case "Склад"
            'с листа "Склад"
            'только диапазон соответствующей выгрузки
            Worksheets("Склад"). _
                Range(Range("res_header").Offset(1, 0), Range("res_header").End(xlDown)).Clear
            clear_results = True
        Case "Отчет"
            'с листа "Отчет"
            'удаляется всё
            Worksheets("Отчет").UsedRange.Clear
            clear_results = True
        Case Else
            MsgBox "Неверно указано имя листа"
            Debug.Print "clear_results(arg_sheet): argument is wrong"
    End Select
End Function


Public Function filter_table() As Boolean
    clear_results ("Склад") 'предварительно очищаем лист Склада
    'фильтр таблицы
    'именованный диапазон db фильтруем по crit в res
    Sheets("Склад").Range("db").AdvancedFilter Action:=xlFilterCopy, _
    CriteriaRange:=Sheets("Склад").Range("crit"), _
    CopyToRange:=Sheets("Склад").Range("res_header"), _
    Unique:=False
    filter_table = True
End Function


Public Function copy_result() As Boolean
    Dim button_report_sheet As Byte
    button_report_sheet = MsgBox("Нажмите 'ОК' для выгрузки отчета на новый лист." _
    & vbNewLine _
    & "Нажмите 'Отмена' для выгрузки отчета на лист 'Отчет'", _
    vbExclamation + vbOKCancel, _
    "Отбор данных")
    
    Select Case button_report_sheet
        Case vbOK
            Dim last_sheet_number As Long
                last_sheet_number = Worksheets.Count
            Dim new_sheet_name_with_number As String
            
                new_sheet_name_with_number = getNewSheetName(new_sheet_report_pattern)
            ActiveWorkbook.Sheets.Add _
                (After:=ActiveWorkbook.Sheets(last_sheet_number)) _
                .Name = new_sheet_name_with_number
                
            copy_from_sklad 'копируем результаты фильтра со "Склада"
            Worksheets(new_sheet_name_with_number).paste _
                (Worksheets(new_sheet_name_with_number).Range("A1"))
            
            Application.CutCopyMode = False 'снимаем флаг копирования Excel
        Case vbCancel
            Dim button_report_append_or_replace As Byte
            button_report_append_or_replace = _
            MsgBox("Нажмите 'ОК' для добавления отчета в конец листа" _
            & vbNewLine _
            & "Нажмите 'Отмена' удаления всех предыдущих отчетов", _
            vbExclamation + vbOKCancel, _
            "Отбор данных")
    
            Select Case button_report_append_or_replace
            Case vbOK
                    paste_results ("append")
            Case vbCancel
                    paste_results ("replace") 'вставляем, предварительно удалив все предыдущие
            Case Else
                    Debug.Print "No arg for paste_results"
            End Select
                
        Case Else
            MsgBox "Копирование отменено", vbInformation, "Отбор данных"
            Exit Function
    End Select
    copy_result = True
End Function


Function copy_from_sklad()
    'для упрощения понимания кода - длинную инструкцию выведем в отдельную функцию
    Worksheets("Склад").Range(Range("res_header"), Range("res_header").End(xlDown)).Copy
    copy_from_sklad = True
End Function


Function paste_results(paste_type_lowercase As String)
    Select Case paste_type_lowercase
        Case "replace"
            clear_results ("Отчет") 'предварительно очищаем лист "Отчет" 'функция удаляет ВСЕ данные с листа!!!
            copy_from_sklad 'копируем результаты фильтра со "Склада"
            Worksheets("Отчет").paste (Worksheets("Отчет").Range("A1"))
            Application.CutCopyMode = False 'снимаем флаг копирования Excel
            paste_results = True
        Case "append"
            copy_from_sklad 'копируем результаты фильтра со "Склада"
                Dim space_between As Byte
                    space_between = 1
                Dim dest_row As Long
                    dest_row = (Worksheets("Отчет").UsedRange.Rows.Count + space_between + 1)
                Dim dest_col As Long
                    dest_col = 1
            Worksheets("Отчет").paste _
                Worksheets("Отчет").Range _
                    (Worksheets("Отчет").Cells(dest_row, dest_col), Worksheets("Отчет").Cells(dest_row, dest_col))
            Application.CutCopyMode = False 'снимаем флаг копирования Excel
            paste_results = True
        Case Else
            MsgBox "Произошла ошибка"
            Debug.Print "Error: paste_results wrong argument"
    End Select
End Function


Sub goBack()
    'переход на лист "Склад"
    Sheets("Склад").Select
    Range("A1").Select
End Sub


Function list_sheets()
    'для отладки
    Dim i As Long
    Dim strFileName As String
    Dim strSheetName As String

    For i = 1 To ActiveWorkbook.Sheets.Count
        strFileName = ActiveWorkbook.FullName
        strSheetName = ActiveWorkbook.Sheets(i).Name
        Debug.Print i & " '" & strSheetName & "'"
    Next
End Function

Function getNewSheetName(new_sheet_report_pattern As String) As String
        Dim i_sheet_name As String
        Dim worksheet_obj As Variant
        Dim new_sheet_report_pattern_length As Integer
            new_sheet_report_pattern_length = Len(new_sheet_report_pattern)
        Dim counter As Integer: counter = 1
        
        For Each worksheet_obj In ActiveWorkbook.Sheets
        i_sheet_name = worksheet_obj.Name
        'если лист с таким названием уже есть
        If StrComp(Left(i_sheet_name, new_sheet_report_pattern_length), _
                        new_sheet_report_pattern, vbTextCompare) = 0 _
            Then counter = counter + 1
        Next worksheet_obj
        getNewSheetName = new_sheet_report_pattern & counter
        'Debug.Print getNewSheetName
End Function

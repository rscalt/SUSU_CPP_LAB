Sub wbook_list_sheets()
    Dim list_name As String
    list_name = "shlist"
    
    Set NewSheet = Sheets.Add(Type:=xlWorksheet)
    For i = 1 To Sheets.Count
        NewSheet.Cells(i, 1).Value = Sheets(i).Name
    Next i
    
    NewSheet.Name = list_name
    NewSheet.Cells(1, 1).Value = list_name
    Sheets("main").Select
End Sub
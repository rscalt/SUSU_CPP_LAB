    system("pause");
    if (!show_constructor_events)
        cout << "\n  Constructor event logging disabled.";

    cout << "\n ==== Testing constructors (static objects) ==== ";
    Ring ring0, ring1, ring2(10, 20), ring3(11, 22, 33, 44);

    cout << endl;
    system("pause");

    cout << "\n ====== Testing ++ and -- operators overload ====== ";

    cout << "\n  Enter new ring parameters: ";
    cin >> ring0;
    cout << ring0;
    cout << "\n  Increasing the ring...";
    ++ring0;
    cout << "\n  Increasing the ring...";
    ++ring0;
    cout << ring0;
    cout << "\n  Decreasing the ring...";
    --ring0;
    cout << ring0;

    cout << endl;
    system("pause");

    cout << "\n ======= Testing (ring 1 + ring 2): ===========";
    cout << ring1 << ring2;

    cout << "\n  Summing rings...";
    cout << (ring1 + ring2);

    cout << endl;
    system("pause");

    cout << "\n ======== Testing (ring 3 - ring 2) :===========";
    cout << ring3;
    cout << ring2;
    cout << "\n  Substracting rings...";
    cout << (ring3 - ring2); 
    cout << endl;
    system("pause");


    cout << "\n ======== Testing > and < operators overload :===========";
    cout << ring0 << ring2;

    cout << "\n  Comparing Rings... (>)";
    ring0 > ring2 ? cout << "\n  [TRUE] ring0 > ring2" : cout << "\n  [FALSE] ring0 < ring2";
    cout << "\n  Comparing Rings...(<)";
    ring0 < ring2 ? cout << "\n  [TRUE] ring0 < ring2" : cout << "\n  [FALSE] ring0 > ring2";

    cout << endl;
    system("pause");
 

    cout << "\n ======== Testing \"==\" operator overload :===========";
    cout << ring0 << ring1 << ring2;

    cout << "\n  Checking if rings are identical (ring0 == ring1)...";
    ring0 == ring1 ? cout << "\n  [TRUE] ring0 == ring1" : cout << "\n  [FALSE] ring0 =/= ring1";

    cout << "\n  Checking if rings are identical (ring0 == ring2)...";
    ring0 == ring2 ? cout << "\n  [TRUE] ring0 == ring2" : cout << "\n  [FALSE] ring0 =/= ring2";

    cout << endl;
    system("pause");

    cout << "\n ======== Testing \"=\" operator overload :===========";
    cout << ring0 << ring1 << ring2;
    cout << "\n  Copying rings...";
    ring0 = ring1 = ring2;
    cout << ring0 << ring1 << ring2;
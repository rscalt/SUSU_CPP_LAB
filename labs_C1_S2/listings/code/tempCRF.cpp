    Distance distance1;
    distance1.showData();
    distance1.getMeters();

    Distance distance2(10U, 20U, "Custom");
    distance2.showData();
    distance2.getMeters();

    Distance distance3(30.55F, 20.45F, "Rounded");
    distance3.showData();
    distance3.getMeters();

    Distance distance_array[3];
    for (int i = 0; i < 3; i++)
        distance_array[i].showData();
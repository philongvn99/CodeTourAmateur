int b = 2;
	int i = 0;
	while (i < 20) {
		if (a > b) { b += a; cout << b << endl; }
		else { a += b; cout << a << endl; }
		i++;
	}
	system("pause");
	if (K == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			flag = 0;
			if (a[i] == b[1])
			{
				for (int j = 1; j < m; j++)
					if (a[j + i] != b[j + 1])
						flag = 1;
				if (flag == 0)
					ans += 1;
			}
		}
	}


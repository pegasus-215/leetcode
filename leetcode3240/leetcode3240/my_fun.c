int minFlips(int** grid, int gridSize, int* gridColSize) {
    int m, n, flip_nums = 0;


    if (gridSize % 2 == 0 && *gridColSize % 2 == 0)
    {
        m = gridSize / 2;
        n = *gridColSize / 2;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num_of_ones = 0;
                num_of_ones = grid[i][j] + grid[i][*gridColSize - j - 1] +
                    grid[gridSize - i - 1][j] +
                    grid[gridSize - i - 1][*gridColSize - j - 1];

                flip_nums += num_of_ones < 3 ? num_of_ones : num_of_ones % 2;
            }
        }
    }
    else if (gridSize % 2 == 1 && *gridColSize % 2 == 0)
    {
        m = (gridSize - 1) / 2;
        n = *gridColSize / 2;

        int num_of_ones = 0, count = 0, num_of_10_couples = 0;

        if (gridSize == 1)
        {
            for (int j = 0; j < n; j++)
            {
                num_of_ones += (grid[0][j] == grid[0][*gridColSize - j - 1] && grid[0][j] == 1) ? 2 : 0;
                num_of_10_couples += (grid[0][j] != grid[0][*gridColSize - j - 1]) ? 1 : 0;
            }

            if (!num_of_ones || (num_of_ones && (num_of_ones % 4 == 0)))
            {
                flip_nums = num_of_10_couples;
            }
            else
            {
                flip_nums = (num_of_10_couples >= 1) ? num_of_10_couples : 2;
            }


            return flip_nums;
        }


        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num_of_ones = 0;
                num_of_ones = grid[i][j] + grid[i][*gridColSize - j - 1] +
                    grid[gridSize - i - 1][j] +
                    grid[gridSize - i - 1][*gridColSize - j - 1];

                flip_nums += num_of_ones < 3 ? num_of_ones : num_of_ones % 2;
            }
        }

        num_of_ones = 0, count = 0, num_of_10_couples = 0;

        for (int j = 0; j < n; j++)
        {
            num_of_ones += (grid[m][j] == grid[m][*gridColSize - j - 1] && grid[m][j] == 1) ? 2 : 0;
            num_of_10_couples += (grid[m][j] != grid[m][*gridColSize - j - 1]) ? 1 : 0;
        }

        if (!num_of_ones || (num_of_ones && (num_of_ones % 4 == 0)))
        {
            flip_nums += num_of_10_couples;
        }
        else
        {
            flip_nums += (num_of_10_couples >= 1) ? num_of_10_couples : 2;
        }
    }
    else if (gridSize % 2 == 0 && *gridColSize % 2 == 1)
    {
        m = gridSize / 2;
        n = (*gridColSize - 1) / 2;

        int num_of_ones = 0, count = 0, num_of_10_couples = 0;

        if (*gridColSize == 1)
        {
            for (int i = 0; i < m; i++)
            {
                num_of_ones += (grid[i][0] == grid[gridSize - i - 1][0] && grid[i][0] == 1) ? 2 : 0;
                num_of_10_couples += (grid[i][0] != grid[gridSize - i - 1][0]) ? 1 : 0;
            }

            if (!num_of_ones || (num_of_ones && (num_of_ones % 4 == 0)))
            {
                flip_nums = num_of_10_couples;
            }
            else
            {
                flip_nums = (num_of_10_couples >= 1) ? num_of_10_couples : 2;
            }


            return flip_nums;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num_of_ones = 0;
                num_of_ones = grid[i][j] + grid[i][*gridColSize - j - 1] +
                    grid[gridSize - i - 1][j] +
                    grid[gridSize - i - 1][*gridColSize - j - 1];

                flip_nums += num_of_ones < 3 ? num_of_ones : num_of_ones % 2;
            }
        }

        num_of_ones = 0, count = 0, num_of_10_couples = 0;

        for (int i = 0; i < m; i++)
        {
            num_of_ones += (grid[i][n] == grid[gridSize - i - 1][n] && grid[i][n] == 1) ? 2 : 0;
            num_of_10_couples += (grid[i][n] != grid[gridSize - i - 1][n]) ? 1 : 0;
        }

        if (!num_of_ones || (num_of_ones && (num_of_ones % 4 == 0)))
        {
            flip_nums += num_of_10_couples;
        }
        else
        {
            flip_nums += (num_of_10_couples >= 1) ? num_of_10_couples : 2;
        }
    }
    else if (gridSize % 2 == 1 && *gridColSize % 2 == 1)
    {
        m = (gridSize - 1) / 2;
        n = (*gridColSize - 1) / 2;

        if (gridSize == 1 && *gridColSize == 1)
        {
            return grid[0][0];
        }
        else if (gridSize == 1)
        {
            int num_of_ones = 0, count = 0, num_of_10_couples = 0;



            for (int j = 0; j < n; j++)
            {
                num_of_ones += (grid[0][j] == grid[0][*gridColSize - j - 1] && grid[0][j] == 1) ? 2 : 0;
                num_of_10_couples += (grid[0][j] != grid[0][*gridColSize - j - 1]) ? 1 : 0;
            }

            if (!num_of_ones || (num_of_ones && (num_of_ones % 4 == 0)))
            {
                flip_nums = num_of_10_couples;
            }
            else
            {
                flip_nums = (num_of_10_couples >= 1) ? num_of_10_couples : 2;
            }


            return flip_nums + grid[0][n];

        }
        else if (*gridColSize == 1)
        {
            int num_of_ones = 0, count = 0, num_of_10_couples = 0;

            for (int i = 0; i < m; i++)
            {
                num_of_ones += (grid[i][0] == grid[gridSize - i - 1][0] && grid[i][0] == 1) ? 2 : 0;
                num_of_10_couples += (grid[i][0] != grid[gridSize - i - 1][0]) ? 1 : 0;
            }

            if (!num_of_ones || (num_of_ones && (num_of_ones % 4 == 0)))
            {
                flip_nums = num_of_10_couples;
            }
            else
            {
                flip_nums = (num_of_10_couples >= 1) ? num_of_10_couples : 2;
            }

            return flip_nums + grid[m][0];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num_of_ones = 0;
                num_of_ones = grid[i][j] + grid[i][*gridColSize - j - 1] +
                    grid[gridSize - i - 1][j] +
                    grid[gridSize - i - 1][*gridColSize - j - 1];

                flip_nums += num_of_ones < 3 ? num_of_ones : num_of_ones % 2;
            }
        }

        int num_of_ones = 0, count = 0, num_of_10_couples = 0;

        for (int j = 0; j < n; j++)
        {
            num_of_ones += (grid[m][j] == grid[m][*gridColSize - j - 1] && grid[m][j] == 1) ? 2 : 0;
            num_of_10_couples += (grid[m][j] != grid[m][*gridColSize - j - 1]) ? 1 : 0;
        }


        for (int i = 0; i < m; i++)
        {
            num_of_ones += (grid[i][n] == grid[gridSize - i - 1][n] && grid[i][n] == 1) ? 2 : 0;
            num_of_10_couples += (grid[i][n] != grid[gridSize - i - 1][n]) ? 1 : 0;
        }

        if (!num_of_ones || (num_of_ones && (num_of_ones % 4 == 0)))
        {
            flip_nums += num_of_10_couples;
        }
        else
        {
            flip_nums += (num_of_10_couples >= 1) ? num_of_10_couples : 2;
        }

        flip_nums += grid[m][n];
    }
    return flip_nums;
}
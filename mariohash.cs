using System;

class Program
{
    static void Main(string[] args)
    {
        int height;

        // Asking the user to input the height of the pyramid
        do
        {
            Console.Write("Height: ");
            if (!int.TryParse(Console.ReadLine(), out height))
            {
                Console.WriteLine("Please enter a valid number.");
                continue;
            }
        }
        // The user can only input a height between 1 and 100
        while (height < 1 || height > 10);

        // Loop to create the rows of the pyramid
        for (int row = height - 1; row >= 0; row--)
        {
            // Loop to create the width of the pyramid
            for (int column = 0; column < 2 * height - 1; column++)
            {
                if (column >= row && column < (2 * height - 1) - row)
                {
                    Console.Write("#");
                }
                else
                {
                    Console.Write(" ");
                }
            }
            Console.WriteLine();
        }
    }
}
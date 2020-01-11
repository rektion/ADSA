using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace AdvancedDatabaseProject
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("This program contains parts 1, 3 and 4,");
            Console.WriteLine("For part 2, please run the C program");
            Part1();
            Part3();
            Part4();
        }

        static int StringToInt(string str)
        {
            float f;

            str = str.Replace('.', ',');
            f = float.Parse(str);
            f *= 100;
            return (Convert.ToInt32(f));
        }

        static void Part1()
        {
            StreamReader sr = new StreamReader("gotham.csv");
            List<string> names = new List<string>();
            int[,] graph = new int[91, 91];
            string line;
            string[] values;
            int x;
            int y;
            PrintPart("Part 1");
            Console.WriteLine("Here is the graph of Gotham before Prim MST method\n");
            Console.ReadKey();
            Console.WriteLine("\tEdge \t\t\t Weight");
            while (!sr.EndOfStream)
            {
                line = sr.ReadLine();
                values = line.Split(';');
                if (!names.Contains(values[0]))
                    names.Add(values[0]);
                if (!names.Contains(values[1]))
                    names.Add(values[1]);
                x = names.IndexOf(values[0]);
                y = names.IndexOf(values[1]);
                graph[x, y] = StringToInt(values[2]);
                graph[y, x] = graph[x, y];
                Console.WriteLine("| " + values[0] + " - " + values[1] + " |" + "\t" + StringToInt(values[2]));
            }
            sr.Close();
            for (int i = 0; i < graph.GetLength(0); i++)
                for (int j = 0; j < graph.GetLength(1); j++)
                {
                    if (graph[i, j] == 0)
                        graph[i, j] = 2000000000;
                }
            MST mst = new MST(graph.GetLength(0), names);
            Console.WriteLine("\nHere is the graph after MST method by Prim algorithm\n");
            Console.ReadKey();
            mst.primMST(graph);
            Console.WriteLine("\nThis is the end of part 1");
            Console.ReadKey();
            Console.Clear();
        }

        static void PrintPart(string part)
        {
            Console.WriteLine("-----------------");
            Console.WriteLine("     " + part + "     ");
            Console.WriteLine("-----------------\n\n");
        }

        static void Part3()
        {
            Random r;
            int bogoVal;
            int smartVal;
            Data bogoData;
            int smartData;

            bogoVal = 0;
            Console.Clear();
            r = new Random();
            Database database = new Database("Joker Corp");
            PrintPart("Part 3");
            Console.WriteLine("Random database creation in progress...");
            for (int i = 300; i >= 0; i--)
                database.AddRandomElem(r, i);
            Console.WriteLine("Creation complete !");
            Console.WriteLine("Each element of the database has un Id and a string value");
            Console.WriteLine("The greedy searching method will now initiate");
            bogoVal = ValueInterface();
            if ((bogoData = database.GreedySearch(bogoVal)) == null)
                Console.WriteLine("No data corresponds to this Id");
            else
            {
                Console.WriteLine("Here is the data :");
                Console.WriteLine("Id = " + bogoData.Id);
                Console.WriteLine("Value = " + bogoData.value);
            }
            Console.WriteLine("Database sorting in progress...");
            database.BinaryInsertionSort();
            Console.WriteLine("Database sorted !");
            Console.WriteLine("The optimized searching method will now initiate");
            smartVal = ValueInterface();
            if ((smartData = database.BinarySearch(smartVal, database.datas, true)) == -1)
                Console.WriteLine("No data corresponds to this Id");
            else
            {
                bogoData = database.datas.ElementAt(smartVal);
                Console.WriteLine("Here is the data :");
                Console.WriteLine("Id = " + bogoData.Id);
                Console.WriteLine("Value = " + bogoData.value);
            }
            Console.WriteLine("This is the end of part 3");
            Console.ReadKey();
            Console.Clear();
        }

        static void Part4()
        {
            Random r = new Random();

            Console.Clear();
            PrintPart("Part 4");
            Console.WriteLine("Random database in a binary tree creation in progress...");
            BinaryTree<Data> db = new BinaryTree<Data>();
            for (int i = 300; i >= 0; i--)
                db.Add(new Data(i, "" + (char)r.Next(32, 127)));
            Console.WriteLine("Creation complete !");
            Console.WriteLine("Each element of the database has un Id and a string value");
            BinaryTreeNode<Data> ret = db.FindById(new Data(ValueInterface(), ""));
            if (ret == null)
                Console.WriteLine("No data corresponds to this Id");
            else
            {
                Console.WriteLine("Here is the data :");
                Console.WriteLine("Id = " + ret.Value.Id);
                Console.WriteLine("Value = " + ret.Value.value);
            }
            Console.WriteLine("Database improvement in progres...");
            AVLTree<Data> db2 = new AVLTree<Data>();
            foreach (Data element in db)
                db2.Add(element);
            Console.WriteLine("Improvement successful !");
            Console.WriteLine("The database is now following Adelson-Velsky and Landis pattern");
            BinaryTreeNode<Data> ret2 = db2.FindById(new Data(ValueInterface(), ""));
            if (ret2 == null)
                Console.WriteLine("No data corresponds to this Id");
            else
            {
                Console.WriteLine("Here is the data :");
                Console.WriteLine("Id = " + ret2.Value.Id);
                Console.WriteLine("Value = " + ret2.Value.value);
            }
            Console.WriteLine("Random databse in a Bayer and McCreight tree creation in progress...");
            Console.WriteLine("(This is an other database)");
            BTree<int, string> db3 = new BTree<int, string>(4); // From 0 to 4 => 5 childrens max
            for (int i = 300; i >= 0; i--)
                db3.Insert(i, "" + (char)r.Next(32, 127));
            Console.WriteLine("Creation successful !");
            Console.WriteLine("Each node can store up to 5 values");
            Entry<int, string> ret3 = db3.Search(ValueInterface());
            if (ret3 == null)
                Console.WriteLine("No data corresponds to this Id");
            else
            {
                Console.WriteLine("Here is the data :");
                Console.WriteLine("Id = " + ret3.Key);
                Console.WriteLine("Value = " + ret3.Pointer);
            }
            Console.WriteLine("This is the end of part 4");
            Console.ReadKey();
            Console.Clear();
        }

        static int ValueInterface()
        {
            int bogoVal;

            bogoVal = 0;
            while (bogoVal == 0)
            {
                Console.WriteLine("Please select an Id you want to look for (between 1 and 300)");
                Console.WriteLine("You can put a number out of this range, but no data will be found");
                try
                {
                    bogoVal = int.Parse(Console.ReadLine());
                }
                catch
                { }
            }
            return bogoVal;
        }
    }
}

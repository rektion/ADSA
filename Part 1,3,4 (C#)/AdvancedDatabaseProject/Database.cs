using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdvancedDatabaseProject
{
    class Database
    {
        public string name;
        public List<Data> datas;

        /// <summary>
        /// Constructor
        /// The database is fulfilled by adding successives elements
        /// </summary>
        /// <param name="name"></param>
        /// <param name="length"></param>
        public Database(string name)
        {
            this.name = name;
            datas = new List<Data>();
        }

        /// <summary>
        /// You don't know what to add ?
        /// This function is made for you !
        /// </summary>
        /// <param name="r"></param>
        public void AddRandomElem(Random r, int Id)
        {
            datas.Add(new Data(Id, "" + (char)r.Next(32, 127)));
        }

        /// <summary>
        /// Returns the data with the specified id
        /// If none corresponds return null
        /// Can be used if the list is not soted but can take a long time
        /// Prefer sort the list then binarySearch in it
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public Data GreedySearch(int key) 
        {
            foreach(Data element in datas)
            {
                if (element.Id == key)
                    return element;
            }
            return null;
        }

        /// <summary>
        /// Returns the index of the specified key in the specified input list
        /// If none corresponds then return the index the key should be
        /// Only use this function if the database is sorted !
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public int BinarySearch(int key, List<Data> search, bool realValue)
        {
            int minNum = 0;
            int maxNum = search.Count - 1;
            int mid;

            mid = 0;
            while (minNum <= maxNum)
            {
                mid = (minNum + maxNum) / 2;
                if (key == search[mid].Id)
                {
                    return mid;
                }
                else if (key < search[mid].Id)
                {
                    if (minNum - maxNum >= -1)
                        return (realValue ? -1 : mid);
                    maxNum = mid - 1;
                }
                else
                {
                    if (minNum == maxNum)
                        return (realValue ? -1 : ++mid);
                    minNum = mid + 1;
                }
            }
            return 0;
        }

        /// <summary>
        /// Sort the database by Binary insertion
        /// </summary>
        public void BinaryInsertionSort() 
        {
            List<Data> datas2;
            int tmp;
            Data dmp;

            datas2 = new List<Data>();
            tmp = datas.Count;
            for(int i = 0; i < tmp; i++) 
            {
                dmp = datas[0];
                datas.RemoveAt(0);
                datas2.Insert(BinarySearch(dmp.Id, datas2, false),dmp);
            }
            datas = datas2;
        }
    }
}

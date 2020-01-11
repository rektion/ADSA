using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdvancedDatabaseProject
{
    class Data : IComparable
    {
        public int Id;
        public string value;

        int IComparable.CompareTo(object obj)
        {
            if (obj == null) return 1;

            Data otherData = obj as Data;
            if (otherData != null)
                return this.Id.CompareTo(otherData.Id);
            else
                throw new ArgumentException("Object is not a Data");

        }

        /// <summary>
        /// Data constructor
        /// Links a key to a value
        /// </summary>
        /// <param name="Id"></param>
        /// <param name="value"></param>
        public Data(int Id, string value) 
        {
            this.Id = Id;
            this.value = value;
        }
    }
}

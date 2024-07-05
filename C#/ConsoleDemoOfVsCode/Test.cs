using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO.Pipes;
using System.Net;
using System.Net.Sockets;
using System.Reflection;
using System.Text;
using System.Windows;
namespace Test{
    class TestProgram{
        public static void main(int argc, string[] argv)
        {
            
        }

        public class Container : ICollection
        {
            private List<object> enumerator = new List<object>();
            public int Count => enumerator.Count();

            public bool IsSynchronized => throw new NotImplementedException();

            public object SyncRoot => throw new NotImplementedException();

            public void CopyTo(Array array, int index)
            {
                throw new NotImplementedException();
            }

            public IEnumerator GetEnumerator()
            {
                return (IEnumerator) enumerator;
            }
        }
    }
}
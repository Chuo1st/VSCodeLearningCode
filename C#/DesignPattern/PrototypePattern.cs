namespace Prototype{
    public class Person:IClonable
    {
        public string name;
        public int age;

        public object Clone()
        {
            return new Person(){name = this.name, age = this.age};
        }
    }

    public interface IClonable{
        public object Clone();
    }
}
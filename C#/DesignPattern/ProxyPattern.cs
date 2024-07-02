namespace ProxyPattern{
    public interface IGiveGifts{
        public void Give();
    }

    public class Person:IGiveGifts{
        public void Give()
        {
            Console.WriteLine("送礼物");
        }
    }

    public class Proxy:IGiveGifts{
        private Person p;
        public Proxy(Person p)
        {
            this.p = p;
        }

        public void Give()
        {
            Console.WriteLine("xxx ");
            p.Give();
        }
    }
}
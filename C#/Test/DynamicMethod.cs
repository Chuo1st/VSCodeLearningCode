
using System.Reflection.Emit;

public class LearnDynamicMethod
{
    public static void CreateDynamicMethod()
    {
        DynamicMethod dymethod = new DynamicMethod("dymethod1", null, null);
        ILGenerator gen = dymethod.GetILGenerator();
    }
}
// See https://aka.ms/new-console-template for more information
using System.ComponentModel;
using System.Numerics;
using System.Reflection;

Console.WriteLine("Hello, World!");

// 通过程序集获取元数据
Assembly assembly = Assembly.GetExecutingAssembly();
var simpleFactory = assembly.GetType("SimpleFactory.SimplePhoneFactory");

// 获取数组类型Type
int[] intergerArray = new int[3];
Type intergerArrayType = intergerArray.GetType();
intergerArrayType = typeof(int[]);
intergerArrayType = typeof(int).MakeArrayType();

// 获取嵌套类型
Type[] nestedType = typeof(Environment).GetNestedTypes();

// 类型名称，命名空间，程序集
Type environmentType = typeof(Environment);
Console.WriteLine($"name: {environmentType.Name}, namespace: {environmentType.Namespace}, Assembly{environmentType.Assembly}");

// 泛型名称
Type unBoundGenericType = typeof(Dictionary<,>); // 未绑定泛型：Dictionary'2
Type boundGenericType = typeof(Dictionary<string, int>); // 绑定泛型：Dictionary'2[strintg, int]

//Activator.CreateInstance(unBoundGenericType); // 运行会发生异常，无法实例化未绑定泛型
Activator.CreateInstance(boundGenericType);


// 1. 调用静态的Activator.CreateInstance方法；
Activator.CreateInstance(typeof(int));
// 2. 调用ConstructorInfo.Invoke方法，并使用Type的GetConstructor方法的返回值作为参数
//typeof(string).GetConstructor(new []{typeof(string)}).Invoke(new object[]{null});




// 反射和成员方法

// 如果在调用GetMembers方法时不传递任何参数，则该方法会返回当前类型（及其基类）的所有公有成员
MemberInfo[] stringMemberInfos = typeof(string).GetMembers(); // 返回所有公共成员
MethodInfo[] stringMethodInfos = typeof(string).GetMethods(); // 返回所有公共方法
FieldInfo[] stringFileInfos = typeof(string).GetFields(); // 返回所有公共字段
EventInfo[] stringEventInfos = typeof(string).GetEvents(); // 返回所有事件
PropertyInfo[] stringPropertyInfos = typeof(string).GetProperties(); // 返回所有公有属性
Type[] stringNestedType = typeof(string).GetNestedTypes(); // 返回所有公共的嵌套类型
ConstructorInfo[] stringContructorInfos = typeof(string).GetConstructors(); //.....

object obj = "1234";
PropertyInfo objProinfo = typeof(string).GetProperty("Length");
Console.WriteLine(objProinfo.GetValue(obj, null));
MethodInfo stringCountMethod = typeof(string).GetMethod("ToString", new Type[0]); // 调用无参数的ToString方法

FieldInfo privateInfo = typeof(Test).GetField("i",BindingFlags.NonPublic | BindingFlags.Instance);
Test t = new Test();
privateInfo.SetValue(t, 3);
Console.WriteLine(privateInfo.GetValue(t));


public class Test{
    private int i = 1;

    public void Show()
    {

    }
}
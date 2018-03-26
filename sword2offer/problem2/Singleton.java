/*
单例设计模式：
    只能有一个实例；
    自己创建唯一实例
    提供外部访问方法
代码：
    私有构造函数
    建立本类对象
    提供公有方法获取实例对象
*/
/*
饿汉式：线程安全，耗费资源
public class singele{
    private static final Single instance = new Single();
    private Single(){

    }
    public static Single getInstance(){
        return instance;
    }
} 
懒汉式：多个线程调用时等待，耗费资源
public class singele{
    private static Single instance;
    private Single(){

    }
    public synchonized static Single getInstance(){
        if(instance == null)
            intance = new Single();
        return instance;
    }
} 
*/
//线程安全：双重检查锁（同步代码块）,volatile关键字禁止指令重排序 （懒汉式）
public class Singele1{
    private static volatile Single1 instance;
    private Single1(){

    }
    public static Single1 getInstance(){
        if(instance == null)
            synchronized(Singele1.class){
                if(instance == null)
                    intance = new Single();
            }
        return instance;
    }
} 
//线程安全：静态内部类 (内部类是一个饿汉式单例，但从外部看是懒汉式的实现)
public class Single2{
    private Single2(){

    }
    private static class InstanceHolder{
        private static final Single2 instance = new Single2();
    }
    public static Single2 getInstance(){
        return InstanceHolder.instance;
    }
}

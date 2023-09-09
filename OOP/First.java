import Test.Second;

public class First {
    public static void Horray() {
        System.out.println("Hello");
    }

    public static void main(String[] args) {
        System.out.print("HELLO WORLD!!");

        int x = Second.getInt();

        System.out.println(x);
    }
}
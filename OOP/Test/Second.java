package Test;

import java.util.Scanner;

public class Second {
    public static int getInt() {
        try (Scanner myObj = new Scanner(System.in)) {
            int num = myObj.nextInt();
            return num;
        }
    }
}
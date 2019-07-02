package com.demo.bot;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Hello! My name is Aid.");
        System.out.println("I was created in 2018.");
        System.out.println("Please, remind me your name.");

        // reading a name
        String userName = scanner.nextLine();

        System.out.println("What a great name you have, " + userName + "!");
        System.out.println("Let me guess your age.");
        System.out.println("Enter remainders of dividing your age by 3, 5 and 7.");

        // reading all remainders
        int rem3, rem5, rem7, userAge;
        rem3 = scanner.nextInt();
        rem5 = scanner.nextInt();
        rem7 = scanner.nextInt();

        userAge = (70*rem3 + 21*rem5 + 15*rem7) % 105;

        System.out.println("Your age is " + userAge + "; that's a good time to start programming!");
    }
}

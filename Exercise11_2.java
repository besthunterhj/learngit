/*
Author: 王俊朗
Class: 软件工程1803
ID: 20181003043
 */

import java.util.*;
public class Exercise11_2
{
    public static void main(String[] args)
    {

    }
}

//class MyDate
//{
//    private int year;
//    private int month;
//    private int day;
//
//    MyDate()
//    {
//        this.year = Date.year;
//        this.month = Date.month;
//        this.day = Date.day;
//    }
//
//}

class Person
{
    private final String name;
    private final String address;
    private final int phoneNumber;
    private final String email;

    Person()
    {

    }

    Person(String newName, String newAddress, int newPhoneNumber, String newEmail)
    {
        this.name = newName;
        this.address = newAddress;
        this.phoneNumber = newPhoneNumber;
        this.email = newEmail;
    }

//    void setName(String newName)
//    {
//        this.name = newName;
//    }
//
//    void setAddress(String newAddress)
//    {
//        this.address = newAddress;
//    }
//
//    void setPhoneNumber(int newPhoneNumber)
//    {
//        this.phoneNumber = newPhoneNumber;
//    }
//
//    void setEmail(String newEmail)
//    {
//        this.email = newEmail;
//    }

    public String toString()
    {
        return "name:" + name + "\naddress:" + address + "\nphoneNumber:" + phoneNumber + "\ne-mail:" + email;
    }

}

class Student extends Person
{
    private String grade;

    Student()
    {

    }

    Student(String newGrade)
    {
        this.grade = newGrade;
    }

    Student(String newName, String newAddress, int newPhoneNumber, String newEmail, String newGrade)
    {
        this.grade = newGrade;
        this.name = newName;
    }

}

class Employee extends Person
{
    private String office;
    private MyDate employmentDate;
    private int salary;

    Employee()
    {

    }

    Employee(String newOffice, MyDate newEmploymentDate, int newSalary)
    {
        this.office = newOffice;
        this.employmentDate = newEmploymentDate;
        this.salary = newSalary;
    }

    Employee(String newName, String newAddress, int newPhoneNumber, String newEmail, String newOffice, MyDate newEmploymentDate, int newSalary)
    {
        this.office = newOffice;
        this.employmentDate = newEmploymentDate;
        this.salary = newSalary;
        setName(newName);
        setAddress(newAddress);
        setPhoneNumber(newPhoneNumber);
        setEmail(newEmail);
    }
}

class Faculty extends Employee
{
    private int level;
    private Date working;
}

class Staff extends Employee
{
    private String title;
}
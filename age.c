#include <stdio.h>

void Check_correction(int *x, int *y, int *z);
int Days31(int bday, int bmonth, int cday, int cmonth, int age);
int Days30(int bday, int bmonth, int cday, int cmonth, int age);
int Feb(int bday, int bmonth, int byear, int cday, int cmonth, int age);
int LeapYear(int byear);

int main() {
    int Bday, Bmonth, Byear;
    int Cday, Cmonth, Cyear;

    printf("Enter Current Date (DD MM YYYY): \n");
    printf("DD/MM/YYYY : ");
    scanf("%d %d %d", &Cday, &Cmonth, &Cyear);
    Check_correction(&Cday, &Cmonth, &Cyear);

    printf("\nEnter Your Birth Date (DD MM YYYY): \n");
    printf("DD/MM/YYYY : ");
    scanf("%d %d %d", &Bday, &Bmonth, &Byear);
    Check_correction(&Bday, &Bmonth, &Byear);

    int age = Cyear - Byear;

    if (Bmonth == 1 || Bmonth == 3 || Bmonth == 5 || Bmonth == 7 || Bmonth == 8 || Bmonth == 10 || Bmonth == 12) {
        age = Days31(Bday, Bmonth, Cday, Cmonth, age);
    } else if (Bmonth == 2) {
        age = Feb(Bday, Bmonth, Byear, Cday, Cmonth, age);
    } else {
        age = Days30(Bday, Bmonth, Cday, Cmonth, age);
    }

    if (age >= 0) {
        printf("\nYour Age: %d years\n", age);
    } else {
        printf("Invalid date entered for birth date.\n");
    }

    return 0;
}

void Check_correction(int *x, int *y, int *z) {
    while (*x > 31 || *x < 1) {
        printf("Invalid Date, Enter again: ");
        scanf("%d", x);
    }
    while (*y > 12 || *y < 1) {
        printf("Invalid Month, Enter again: ");
        scanf("%d", y);
    }
    while (*z < 1) {
        printf("Invalid Year, Enter again: ");
        scanf("%d", z);
    }
}

int Days31(int bday, int bmonth, int cday, int cmonth, int age) {
    if (bmonth == cmonth && bday == cday) {
        printf("Happy Birthday!\n");
    }
    if (bmonth > cmonth) {
        age--;
    } else if (bmonth == cmonth && bday > cday) {
        age--;
    }
    return age;
}

int Days30(int bday, int bmonth, int cday, int cmonth, int age) {
    if (bday > 30) {
        printf("This month cannot have more than 30 days, Enter again: ");
        return -1;
    }
    if (bmonth == cmonth && bday == cday) {
        printf("Happy Birthday!\n");
    }
    if (bmonth > cmonth) {
        age--;
    } else if (bmonth == cmonth && bday > cday) {
        age--;
    }
    return age;
}

int Feb(int bday, int bmonth, int byear, int cday, int cmonth, int age) {
    int max = 28;
    if (LeapYear(byear)) {
        max = 29;
    }
    if (bday > max) {
        printf("February cannot have that many days in year %d. Maximum days: %d\n", byear, max);
        return -1;
    }
    if (bmonth == cmonth && bday == cday) {
        printf("Happy Birthday!\n");
    }
    if (bmonth > cmonth) {
        age--;
    } else if (bmonth == cmonth && bday > cday) {
        age--;
    }
    return age;
}

int LeapYear(int byear) {
    if (byear % 4 == 0) {
        if (byear % 100 == 0) {
            if (byear % 400 == 0) {
                return 1;
            } else {
                return 0;  
            }
        }
        return 1;  
    }
    return 0;  
}
//Age calculator made by me hehehehehehe

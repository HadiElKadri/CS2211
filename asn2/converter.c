#include <stdio.h>
//AUTHOR: Hadi El-Kadri
//Functions made
int converter(int Anumber);
float KiloTOMILES(float a);
float MilesTOKILOS(float a);
float MeterTOFEET(float a);
float FeetTOMETER(float a);
float CentiTOINCHES(float a);
float InchesTOCENTI(float a);
float CelsiusTOFAHREN(float a);
float FahrenTOCELSIUS(float a);

//This is main
int main() {
    // Gathering input from the user for a desired operation
    int Anumber = 0;
    printf("Hello. Please enter a number for any given operation. \n\n");
    printf("Enter the number 1 for conversion between : Kilometers and Miles \n");
    printf("Enter the number 2 for conversion between : Meters and Feet \n");
    printf("Enter the number 3 for conversion between : Centimetres and Inches \n");
    printf("Enter the number 4 for conversion between : Celsius and Fahrenheit \n");
    printf("Enter the number 5 to QUIT this program. \n");
    printf("\n");
    printf("Please enter your desired number now: \n");
    scanf(" %d", &Anumber);
    printf("\n");

    //Calling the converter function
    converter(Anumber);

    //After converter has been ran through, if the desired operation was not 5 (quit), re-ask for input
    if (Anumber != 5) {
        Anumber = 0;
        main();
    }
    //Quit program if 5 is input
    else return 0;
}

//Function for conversion from kilometers to miles
float KiloTOMILES(float a){
    float b = a * .621371;
    return b;
}

//Function for conversion from miles to kilometers
float MilesTOKILOS(float a){
    float b = a * 1.60934;
    return b;
}

//Function for conversion from meters to feet
float MeterTOFEET(float a){
    float b = a * 3.28084;
    return b;
}

//Function for conversion from feet to meters
float FeetTOMETER(float a){
    float b = a * 0.3048;
    return b;
}

//Function for conversion from centimetres to inches
float CentiTOINCHES(float a){
    float b = a * 0.393701;
    return b;
}

//Function for conversion from inches to centimetres
float InchesTOCENTI(float a){
    float b = a * 2.54;
    return b;
}

//Function for conversion from celsius to fahrenheit
float CelsiusTOFAHREN(float a){
    float b = (a * 9/5) + 32;
    return b;
}

//Function for conversion from fahrenheit to celsius
float FahrenTOCELSIUS(float a){
    float b = (a - 32) * 5/9;
    return b;
}

//Function converter that uses the conversion functions to make the calculations for the desired operation
int converter(int Anumber){
    //If the number is not of the given, finish
    if (Anumber != 1 && Anumber != 2 && Anumber != 3 && Anumber != 4 && Anumber != 5 ){
        printf("You have entered an invalid input. \n");
        printf("Please try again! \n");
        printf("\n");
    }

    //If the desired operation is 5, quit
    else if (Anumber == 5){
        return 0;
    }

    //If the desired operation is 1, ask which for what way the conversion goes
    else if (Anumber == 1){
        char conversion;
        printf("Type 'K' for conversion from Kilometer to Mile. \n");
        printf("Type 'M' for conversion from Mile to Kilometer. \n");
        printf("\n");
        printf("Please specify your conversion type: \n");
        scanf(" %c", &conversion);
        printf("\n");

        //If an invalid char was entered, ask again
        while (conversion != 'k' && conversion != 'K' && conversion != 'M' && conversion != 'm') {
            printf("You have entered invalid input! Please try again. \n");
            printf("Type 'K' for conversion from Kilometer to Mile. \n");
            printf("Type 'M' for conversion from Mile to Kilometer. \n");
            printf("\n");
            printf("Please specify your conversion type: \n");
            scanf(" %c", &conversion);
            printf("\n");
        }

        //If the conversion is from kilometers to miles, ask for the length and use the function designed for the specified conversion
        if (conversion == 'K' || conversion == 'k'){
            float length = 0;
            printf("Please input a desired length (kilometers): \n");
            scanf(" %f", &length);
            float conversion = KiloTOMILES(length);
            printf("This is equivalent to " "%f",conversion);
            printf(" miles. \n");
            printf("\n");
        }

        //If the conversion is from miles to kilometers, ask for the length and use the function designed for the specified conversion
        else if (conversion == 'M' || conversion == 'm'){
            float length = 0;
            printf("Please input a desired length (miles): ");
            scanf(" %f", &length);
            float conversion = MilesTOKILOS(length);
            printf("This is equivalent to " "%f",conversion);
            printf(" kilometers. \n");
            printf("\n");
        }
    }

    //If the desired operation is 2, ask which for what way the conversion goes
    else if(Anumber == 2){
        char conversion;
        printf("Type 'M' for conversion from Meter to Feet. \n");
        printf("Type 'F' for conversion from Feet to Meter. \n");
        printf("\n");
        printf("Please specify your conversion type: \n");
        scanf(" %c", &conversion);
        printf("\n");

        //If an invalid char was entered, ask again
        while (conversion != 'f' && conversion != 'F' && conversion != 'M' && conversion != 'm') {
            printf("You have entered invalid input! Please try again. \n");
            printf("Type 'M' for conversion from Meter to Feet. \n");
            printf("Type 'F' for conversion from Feet to Meter. \n");
            printf("\n");
            printf("Please specify your conversion type: \n");
            scanf(" %c", &conversion);
            printf("\n");
        }

        //If the conversion is from meters to feet, ask for the length and use the function designed for the specified conversion
        if (conversion == 'M' || conversion == 'm'){
            float length = 0;
            printf("Please input a desired length (meters): \n");
            scanf(" %f", &length);
            float conversion = MeterTOFEET(length);
            printf("This is equivalent to " "%f",conversion);
            printf(" feet. \n");
            printf("\n");
        }

        //If the conversion is from feet to meters, ask for the length and use the function designed for the specified conversion
        else if (conversion == 'F' || conversion == 'f'){
            float length = 0;
            printf("Please input a desired length (feet): ");
            scanf(" %f", &length);
            float conversion = FeetTOMETER(length);
            printf("This is equivalent to " "%f",conversion);
            printf(" meters. \n");
            printf("\n");
        }

    }

    //If the desired operation is 3, ask which for what way the conversion goes
    else if(Anumber == 3){
        char conversion;
        printf("Type 'C' for conversion from Centimetre to Inch. \n");
        printf("Type 'I' for conversion from Inch to Centimetre. \n");
        printf("\n");
        printf("Please specify your conversion type: \n");
        scanf(" %c", &conversion);
        printf("\n");

        //If an invalid char was entered, ask again
        while (conversion != 'C' && conversion != 'c' && conversion != 'I' && conversion != 'i') {
            printf("You have entered invalid input! Please try again. \n");
            printf("Type 'C' for conversion from Centimetre to Inch. \n");
            printf("Type 'I' for conversion from Inch to Centimetre. \n");
            printf("\n");
            printf("Please specify your conversion type: \n");
            scanf(" %c", &conversion);
            printf("\n");
        }

        //If the conversion is from centimetres to inches, ask for the length and use the function designed for the specified conversion
        if (conversion == 'C' || conversion == 'c'){
            float length = 0;
            printf("Please input a desired length (centimetres): \n");
            scanf(" %f", &length);
            float conversion = CentiTOINCHES(length);
            printf("This is equivalent to " "%f",conversion);
            printf(" inches. \n");
            printf("\n");
        }

        //If the conversion is from inches to centimetres, ask for the length and use the function designed for the specified conversion
        else if (conversion == 'I' || conversion == 'i'){
            float length = 0;
            printf("Please input a desired length (inches): ");
            scanf(" %f", &length);
            float conversion = InchesTOCENTI(length);
            printf("This is equivalent to " "%f",conversion);
            printf(" centimetres. \n");
            printf("\n");
        }

    }

    //If the desired operation is 4, ask which for what way the conversion goes
    else if(Anumber == 4){
        char conversion;
        printf("Type 'C' for conversion from Celsius to Fahrenheit. \n");
        printf("Type 'F' for conversion from Fahrenheit to Celsius. \n");
        printf("\n");
        printf("Please specify your conversion type: \n");
        scanf(" %c", &conversion);
        printf("\n");

        //If an invalid char was entered, ask again
        while (conversion != 'C' && conversion != 'c' && conversion != 'F' && conversion != 'f') {
            printf("You have entered invalid input! Please try again. \n");
            printf("Type 'C' for conversion from Celsius to Fahrenheit. \n");
            printf("Type 'F' for conversion from Fahrenheit to Celsius. \n");
            printf("\n");
            printf("Please specify your conversion type: \n");
            scanf(" %c", &conversion);
            printf("\n");
        }

        //If the conversion is from celsius to fahrenheit, ask for the length and use the function designed for the specified conversion
        if (conversion == 'C' || conversion == 'c'){
            float temperature = 0;
            printf("Please input a desired temperature (celsius): \n");
            scanf(" %f", &temperature);
            float conversion = CelsiusTOFAHREN(temperature);
            printf("This is equivalent to " "%f",conversion);
            printf(" degrees fahrenheit. \n\n");
        }

        //If the conversion is from fahrenheit to celsius, ask for the length and use the function designed for the specified conversion
        else if (conversion == 'F' || conversion == 'f'){
            float temperature = 0;
            printf("Please input a desired temperature (fahrenheit): ");
            scanf(" %f", &temperature);
            float conversion = FahrenTOCELSIUS(temperature);
            printf("This is equivalent to " "%f",conversion);
            printf(" degrees celsius. \n");
            printf("\n");
        }
    }
}

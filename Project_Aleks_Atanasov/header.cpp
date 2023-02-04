#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "header.h"  //include header file
using namespace std;
 
double Vehicle::getTotalPrice()  // method that calculates total price of a car - this will be later used for all vehicles
{
	return (getTotalRentPrice() + getRefillTankPrice());
}

Car::Car()  // car default constructor
{
	name = " ";
	model = " ";
	color = " ";
	yearOfProduction = 0;
	horsePower = 0;
	mileage = 0;
	transmission = " ";
	dailyRentPrice = 0.0;
	rentDuration = 0;
	tankAmount = 0.0;
	tankAmountAfterRent = 0.0;
	paidProtectionPlus = false;
	protectionPlus = 0.0;
}

//double Car::getTotalPrice()
//{
//	return (getTotalRentPrice() + getRefillTankPrice());
//}

double Car::getTotalRentPrice()  // calculating the rent price for car
{
	double totalPrice;
	if (paidProtectionPlus == true)
		totalPrice = rentDuration * dailyRentPrice + protectionPlus;
	else
		totalPrice = rentDuration * dailyRentPrice;
	return totalPrice;

}

double Car::getRefillTankPrice() // calculating the refill price for car
{
	double refillPrice;

	if (fuelType == petrol)
		refillPrice = ((tankAmount - tankAmountAfterRent) * petrolPrice);
	else if (fuelType == diesel)
		refillPrice = (tankAmount - tankAmountAfterRent) * dieselPrice;
	else if (fuelType == lpg)
		refillPrice = (tankAmount - tankAmountAfterRent) * lpgPrice;
	else if (fuelType == electric)
		refillPrice = (tankAmount - tankAmountAfterRent) * electrictyKWHPrice;

	return refillPrice;
}



double Electric::getRefillTankPrice()  // here we call the refill price method from car class
{
	return Car::getRefillTankPrice();
}

double Van::getTotalRentPrice()
{
	double totalPrice;
	if (vanType == cargo) 
		totalPrice = Car::getTotalRentPrice() * 1.5;  // here we call the rent price method from car class and multiply x1.5
	else if (vanType == passenger)
	{
		if (numOfSeats > 7)
			totalPrice = Car::getTotalRentPrice() + 100;
		else
			totalPrice = Car::getTotalRentPrice();
	}
	return totalPrice;

}

double Luxury::getTotalRentPrice()
{
	double totalPrice;
	if ( Car::getHorsePower() > 500 && ( sportsMode == true || cabrio == true))
		totalPrice = Car::getTotalRentPrice() + 2.5 * Car::getProtectionPlus(); // here we call the getProtectionPlus() getter  car class and multiply x2.5
	else 
		totalPrice = Car::getTotalRentPrice() + 2 * Car::getProtectionPlus();
	return totalPrice;

}



double Scooter::getTotalRentPrice() // overriding the total rent price method for scooters
{
	return (startingFee + durationMinutes * pricePerMinute);
}

double Scooter::getRefillTankPrice() // overriding the total refill price method for scooters to 0, because scooters dont need refill
{
	return 0.0;
}



double Bike::getRefillTankPrice()  // overriding the total refill price method for scooters to 0, because bikes dont need refill
{
	return 0.0;
}

double Bike::getTotalRentPrice() // overriding the total rent price method for bikes
{
	return durationHours * pricePerHour;
}



double Kart::getRefillTankPrice()  // overriding the total refill price method for scooters to 0, because karts dont need refill
{
	return 0.0;
}
 
double Kart::getTotalRentPrice()  // overriding the total rent price method for Karts
{
	return numberOfLaps * pricePerLap;
}

double RX250::getTotalRentPrice() 
{
	return kartStartingFee + (1.2* (Kart::getTotalRentPrice()));
}

double Double::getTotalRentPrice()
{
	return 1.5* Kart::getTotalRentPrice();
}


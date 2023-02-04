#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// declaring constant values for the types of the fuel 
const double petrolPrice = 2.94;
const double dieselPrice = 3.14;
const double lpgPrice = 1.44;
const double electrictyKWHPrice = 0.16;

enum FuelType { petrol, diesel, lpg, electric };  // creating enum type - FuelType so we can differntiate cars by their fuelType
enum VanType { cargo, passenger };   // creating enum type - VanType so we can differntiate Vans by their vanType
class Vehicle {
public:
	
	virtual double getTotalRentPrice() = 0;  // creating virtual methods to be overriden
	virtual double getRefillTankPrice() = 0;
	virtual double getTotalPrice();
	virtual string getName() = 0;
};

class Car : public Vehicle {  // class Car inherits Vehicle
private:
	string name;
	string model;
	string color;
	int yearOfProduction;
	int horsePower;
	long mileage;
	string transmission;
	FuelType fuelType;
	double dailyRentPrice;
	int rentDuration;
	double tankAmount;
	double tankAmountAfterRent;
	bool paidProtectionPlus;
	double protectionPlus;
public:
	Car();
	Car(string name, string model, string color, int yearOfProduction, int horsePower, string transmission, FuelType fuelType,
		double dailyRentPrice, int rentDuration, double tankAmount, double tankAmountAfterRent, bool paidProtectionPlus, double protectionPlus) {
		setName(name);
		setModel(model);
		setYearOfProduction(yearOfProduction);
		setHorsePower(horsePower);
		setTransmission(transmission);
		setDailyRentPrice(dailyRentPrice);
		setRentDuration(rentDuration);
		setColor(color);
		setTankAmount(tankAmount);
		setTankAmountAfterRent(tankAmountAfterRent);
		setPaidProtectionPlus(paidProtectionPlus);
		setProtectionPlus(protectionPlus);
		setFuelType(fuelType);
	}; // getters and setters for the attributes
	string getName() {
		return name;
	}
	string getModel() {
		return model;
	}
	int getYearOfProduction() {
		return yearOfProduction;
	}
	int getHorsePower() {
		return horsePower;
	}
	string getTransmission() {
		return transmission;
	}
	double getDailyRentPrice() {
		return dailyRentPrice;
	}
	int getRentDuration() {
		return rentDuration;
	}
	string getColor() {
		return color;
	}
	double getTankAmount() {
		return tankAmount;
	}
	double getTankAmountAfterRent() {
		return tankAmountAfterRent;
	}
	bool getPaidProtectionPlus() {
		return paidProtectionPlus;
	}
	double getProtectionPlus() {
		return protectionPlus;
	}
	FuelType getFuelType() {
		return fuelType;
	}

	void setName(string name) {
		this->name = name;
	}
	void setModel(string model) {
		this->model = model;
	}
	void setYearOfProduction(int yearOfProduction) {
		this->yearOfProduction = (yearOfProduction > 0) ? yearOfProduction : 0;
	}
	void setHorsePower(int horsePower) {
		this->horsePower = (horsePower > 0) ? horsePower : 0;
	}
	void setTransmission(string transmission) {
		this->transmission = transmission;
	}
	void setDailyRentPrice(double dailyRentPrice) {
		this->dailyRentPrice = (dailyRentPrice > 0) ? dailyRentPrice : 0;
	}
	void setRentDuration(int rentDuration) {
		this->rentDuration = (rentDuration > 0) ? rentDuration : 0;
	}
	void setColor(string color) {
		this->color = color;
	}
	void setTankAmount(double tankAmount) {
		this->tankAmount = (tankAmount > 0) ? tankAmount : 0;
	}
	void setTankAmountAfterRent(double tankAmountAfterRent) {
		this->tankAmountAfterRent = tankAmountAfterRent;
	}
	void setPaidProtectionPlus(bool paidProtectionPlus) {
		this->paidProtectionPlus = paidProtectionPlus;
	}
	void setProtectionPlus(double protectionPlus) {
		this->protectionPlus = protectionPlus;
	}
	void setFuelType(FuelType fuelType) {
		this->fuelType = fuelType;
	}

	//double getTotalPrice();
	double getTotalRentPrice();
	double getRefillTankPrice();
};


class Electric : public Car {
public:
	Electric();
	Electric(string name, string model, string color,
		int yearOfProduction, int horsePower, string transmission, FuelType fuelType, double dailyRentPrice, int rentDuration,
		double tankAmount, double tankAmountAfterRent, bool paidProtectionPlus, double protectionPlus) : Car(name, model, color, yearOfProduction, horsePower,
			transmission, fuelType, dailyRentPrice, rentDuration, tankAmount, tankAmountAfterRent, paidProtectionPlus, protectionPlus) {
	};  // Electric inherits class Car
	
	double getRefillTankPrice();
};

class Van : public Car { // Van inherits class Car and has 3 additional new attributes
private:
	int numOfSeats;  
	VanType vanType;
	int numOfDoors;
public:
	Van();
	Van(int numOfSeats, VanType vanType, int numOfDoors, string name, string model, string color,
		int yearOfProduction, int horsePower, string transmission, FuelType fuelType, double dailyRentPrice,
		int rentDuration, double tankAmount, double tankAmountAfterRent, bool paidProtectionPlus, double protectionPlus) : Car(name, model, color, yearOfProduction, horsePower, transmission, fuelType,
			dailyRentPrice, rentDuration, tankAmount, tankAmountAfterRent, paidProtectionPlus, protectionPlus) {
		setNumOfSeats(numOfSeats);
		setVanType(vanType);
		setNumOfDoors(numOfDoors);
	};
	int getNumOfSeats() {
		return numOfSeats;
	}
	VanType getVanType() {
		return vanType;
	}
	int getNumOfDoors() {
		return numOfDoors;
	}

	void setNumOfSeats(int numOfSeats) {
		this->numOfSeats = (numOfSeats > 0) ? numOfSeats : 0;
	}
	void setVanType(VanType vanType) {
		this->vanType = vanType;
	}
	void setNumOfDoors(int numOfDoors) {
		this->numOfDoors = (numOfDoors > 0) ? numOfDoors : 0;
	}

	double getTotalRentPrice();
};

class Luxury : public Car { // Luxury inherits class Car and has 2 additional new attributes
private:
	bool sportsMode;
	bool cabrio;
public:
	Luxury();
	Luxury(bool sportsMode, bool cabrio, string name, string model, string color,
		int yearOfProduction, int horsePower, string transmission, FuelType fuelType, double dailyRentPrice,
		int rentDuration, double tankAmount, double tankAmountAfterRent, bool paidProtectionPlus, double protectionPlus) : Car(name, model, color, yearOfProduction, horsePower, transmission, fuelType,
			dailyRentPrice, rentDuration, tankAmount, tankAmountAfterRent, paidProtectionPlus, protectionPlus) {
		setSportsMode(sportsMode);
		setCabrio(cabrio);
	};
	bool getSportsMode() {
		return sportsMode;
	}
	bool getCabrio() {
		return cabrio;
	}

	void setSportsMode(bool sportsMode) {
		this->sportsMode = sportsMode;
	}
	void setCabrio(bool cabrio) {
		this->cabrio = cabrio;
	}

	double getTotalRentPrice();
};

class Scooter : public Vehicle {  // Scooter inherits class Vehicle(we will use only the getTotalprice() method and getName() from the base class) and has additional new attributes
private:
	string name;
	double startingFee;
	double durationMinutes;
	double pricePerMinute;
	int topSpeed;
	double weight;
public:
	Scooter();
	Scooter(string name, double startingFee, double durationMinutes, double pricePerMinute, int topSpeed, double weight) {
		setName(name);
		setStartingFee(startingFee);
		setDurationMinutes(durationMinutes);
		setPricePerMinute(pricePerMinute);
		setTopSpeed(topSpeed);
		setWeight(weight);
	};
	string getName() {
		return name;
	}
	double getStartingFee() {
		return startingFee;
	}
	double getDurationMinutes() {
		return durationMinutes;
	}
	double getPricePerMinute() {
		return pricePerMinute;
	}
	int getTopSpeed() {
		return topSpeed;
	}
	double getWeight() {
		return weight;
	}

	void setName(string name) {
		this->name = name;
	}
	void setStartingFee(double startingFee) {
		this->startingFee = (startingFee > 0) ? startingFee : 0;
	}
	void setDurationMinutes(double durationMinutes) {
		this->durationMinutes = (durationMinutes > 0) ? durationMinutes : 0;
	}
	void setPricePerMinute(double pricePerMinute) {
		this->pricePerMinute = (pricePerMinute > 0) ? pricePerMinute : 0;
	}
	void setTopSpeed(int topSpeed) {
		this->topSpeed = (topSpeed > 0) ? topSpeed : 0;
	}
	void setWeight(double weight) {
		this->weight = (weight > 0) ? weight : 0;
	}

	double getTotalRentPrice();
	double getRefillTankPrice();
};

class Bike : public Vehicle { // Bike inherits class Vehicle(we will use only the getTotalprice() method and getName() from the base class) and has additional new attributes
private:
	string name;
	int numOfWheels;
	double pricePerHour;
	double durationHours;
	int gears;
	string color;
	int wheelsSize;
public:
	Bike();
	Bike(string name, int numOfWheels, double pricePerHour, double durationHours, int gears, string color, int wheelsSize) {
		setName(name);
		setNumOfWheels(numOfWheels);
		setPricePerHour(pricePerHour);
		setDurationHours(durationHours);
		setGears(gears);
		setColor(color);
		setPricePerHour(wheelsSize);
	};
	string getName() {
		return name;
	}
	int getNumOfWheels() {
		return numOfWheels;
	}
	double getPricePerHour() {
		return pricePerHour;
	}
	double getDurationHours() {
		return durationHours;
	}
	int getGears() {
		return gears;
	}
	string getColor() {
		return color;
	}
	int getWheelsSize() {
		return wheelsSize;
	}

	void setName(string name) {
		this->name = name;
	}
	void setNumOfWheels(int numOfWheels) {
		this->numOfWheels = (numOfWheels > 0) ? numOfWheels : 0;
	}
	void setPricePerHour(double pricePerHour) {
		this->pricePerHour = (pricePerHour > 0) ? pricePerHour : 0;
	}
	void setDurationHours(double durationHours) {
		this->durationHours = (durationHours > 0) ? durationHours : 0;
	}
	void setGears(int gears) {
		this->gears = (gears > 0) ? gears : 0;
	}
	void setColor(string color) {
		this->color = color;
	}
	void setPricePerHour(int wheelsSize) {
		this->wheelsSize = (wheelsSize > 0) ? wheelsSize : 0;
	}

	
	double getRefillTankPrice();
	double getTotalRentPrice();
};

class Kart : public Vehicle {  // Kart inherits class Vehicle(we will use only the getTotalprice() method and getName() from the base class) and has additional new attributes
private:
	string name;
	int numberOfLaps;
	double pricePerLap;
	int number;
	int horsePower;
	int maxSpeed;
public:
	Kart();
	Kart(string name, int numberOfLaps, double pricePerLap, int number, int horsePower, int maxSpeed) {
		setName(name);
		setNumberOfLaps(numberOfLaps);
		setPricePerLap(pricePerLap);
		setNumber(number);
		setHorsePower(horsePower);
		setMaxSpeed(maxSpeed);
	};
	string getName() {
		return name;
	}
	int getNumberOfLaps() {
		return numberOfLaps;
	}
	double getPricePerLap() {
		return pricePerLap;
	}
	int getNumber() {
		return number;
	}
	int getHorsePower() {
		return horsePower;
	}
	int getMaxSpeed() {
		return maxSpeed;
	}

	void setName(string name) {
		this->name = name;
	}
	void setNumberOfLaps(int numberOfLaps) {
		this->numberOfLaps = (numberOfLaps > 0) ? numberOfLaps : 0;
	}
	void setPricePerLap(double pricePerLap) {
		this->pricePerLap = (pricePerLap > 0) ? pricePerLap : 0;
	}
	void setNumber(int number) {
		this->number = (number > 0) ? number : 0;
	}
	void setHorsePower(int horsePower) {
		this->horsePower = (horsePower > 0) ? horsePower : 0;
	}
	void setMaxSpeed(int maxSpeed) {
		this->maxSpeed = (maxSpeed > 0) ? maxSpeed : 0;
	}

	double getRefillTankPrice();
	double getTotalRentPrice();
};

class RX7 : public Kart {
public:
	RX7();
	RX7(string name, int numberOfLaps, double pricePerLap, int number , int horsePower, int maxSpeed) : Kart(name, numberOfLaps, pricePerLap, number, horsePower, maxSpeed) {};
};

class RX250 : public Kart {
private:
	double kartStartingFee;
	bool paddleShifters;
public:
	RX250();
	RX250(double kartStartingFee, bool paddleShifters, string name, int numberOfLaps, double pricePerLap, int number, int horsePower, int maxSpeed)
		: Kart(name, numberOfLaps, pricePerLap, number, horsePower, maxSpeed) {
		setKartStartingFee(kartStartingFee);
		setPaddleShifters(paddleShifters);
	};
	double getKartStartingFee() {
		return kartStartingFee;
	}
	bool getPaddleShifters() {
		return paddleShifters;
	}

	void setKartStartingFee(double kartStartingFee) {
		this->kartStartingFee = (kartStartingFee > 0) ? kartStartingFee : 0;
	}
	void setPaddleShifters(bool paddleShifters) {
		this->paddleShifters = paddleShifters;
	}

	double getTotalRentPrice();
};

class Double : public Kart {
private:
	int capacity;
	double weightLimit;
public:
	Double();
	Double(int capacity, double weightLimit, string name, int numberOfLaps, double pricePerLap, int number, int horsePower, int maxSpeed)
		: Kart(name, numberOfLaps, pricePerLap, number, horsePower, maxSpeed) {
		setCapacity(capacity);
		setWeightLimit(weightLimit);
	};
	int getCapacity() {
		return capacity;
	}
	double getWeightLimit() {
		return weightLimit;
	}

	void setCapacity(int capacity) {
		this->capacity = (capacity > 2) ? capacity : 2;
	}
	void setWeightLimit(double weightLimit) {
		this->weightLimit = (weightLimit > 0) ? weightLimit : 0;
	}

	double getTotalRentPrice();
};

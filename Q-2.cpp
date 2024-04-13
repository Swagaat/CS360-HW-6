#include <iostream>
#include <vector>

// Abstract class for CarbonFootprint
class CarbonFootprint {
public:
    virtual double getCarbonFootprint() const = 0; // Pure virtual function
    virtual void printInfo() const = 0; // Print identifying information
    virtual ~CarbonFootprint() {} // Virtual destructor
};

// Building class
class Building : public CarbonFootprint {
private:
    double energyConsumption; // Energy consumed by the building (in kWh)

public:
    Building(double energy) : energyConsumption(energy) {}

    double getCarbonFootprint() const override {
        // Calculate carbon footprint based on energy consumption
        return energyConsumption * 0.5; // Example formula (adjust as needed)
    }

    void printInfo() const override {
        std::cout << "Building: Energy Consumption = " << energyConsumption << " kWh\n";
    }
};

// Car class
class Car : public CarbonFootprint {
private:
    double fuelConsumption; // Fuel consumed by the car (in liters)

public:
    Car(double fuel) : fuelConsumption(fuel) {}

    double getCarbonFootprint() const override {
        // Calculate carbon footprint based on fuel consumption
        return fuelConsumption * 2.3; // Example formula (adjust as needed)
    }

    void printInfo() const override {
        std::cout << "Car: Fuel Consumption = " << fuelConsumption << " liters\n";
    }
};

// Bicycle class
class Bicycle : public CarbonFootprint {
public:
    double getCarbonFootprint() const override {
        // Bicycles have a negligible carbon footprint
        return 0.0;
    }

    void printInfo() const override {
        std::cout << "Bicycle: Environmentally friendly!\n";
    }
};

int main() {
    std::vector<CarbonFootprint*> footprintObjects;

    // Create instances of each class
    Building myHouse(5000); // Example energy consumption in kWh
    Car myCar(100); // Example fuel consumption in liters
    Bicycle myBike;

    // Add pointers to the vector
    footprintObjects.push_back(&myHouse);
    footprintObjects.push_back(&myCar);
    footprintObjects.push_back(&myBike);

    // Calculate and print carbon footprints
    for (const auto& obj : footprintObjects) {
        obj->printInfo();
        std::cout << "Carbon Footprint: " << obj->getCarbonFootprint() << " kg CO2\n\n";
    }

    // Clean up (no dynamic memory allocation, so no explicit cleanup needed)

    return 0;
}

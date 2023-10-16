# Project README

## Overview

This project is designed to manage and analyze options data through various models such as Black-Scholes-Merton (BSM), Heston, and SABR. The main functionalities include reading and validating data, verifying put-call parity, calculating option prices, Greeks, implied volatilities, and constructing the volatility surface.

## File Structure

- **main.cpp**: Coordinates between various classes and functions.
- **OptionData.csv**: Contains the input data.
- **PCPChecker**: Manages Put-Call Parity checking.
  - **PCPChecker.h/.cpp**: Manages PCP arbitrages.
- **BSMModel**: Handles Black-Scholes-Merton Model operations.
  - **BSMModel.h/.cpp**: Related to BSM option pricing.
- **AdvancedModels**: Implements Heston and SABR models.
  - **HestonModel.h/.cpp**: Related to the Heston Model.
  - **SABRModel.h/.cpp**: Related to the SABR Model.
- **Utilities**: Contains utility classes/functions.
  - **FileReader.h/.cpp**: Manages data reading from files.
  - **DataTypes.h**: Stores option data, parameters, etc.
- **VolatilitySurface**: Related to volatility surface analysis.
  - **VolatilitySurface.h/.cpp**: Constructs and analyzes the volatility surface.

## Classes and Responsibilities

### 1. **PCPChecker**
   - **Responsibilities**: Verifies put-call parity and identifies arbitrage opportunities.
   - **Methods**:
     - `verifyPCP()`
     - `logArbitrageOpportunity()`

### 2. **BSMModel**
   - **Responsibilities**: Manages calculations related to BSM.
   - **Methods**:
     - `calculateOptionPrice()`
     - `calculateGreeks()`
     - `computeImpliedVolatility()`

### 3. **FileReader**
   - **Responsibilities**: Manages data reading and validation.
   - **Methods**:
     - `readData()`
     - `validateData()`

### 4. **HestonModel**
   - **Responsibilities**: Implements the Heston model functionalities.
   - **Methods**:
     - `calibrateParameters()`
     - `calculateOptionPrice()`
     - `calculateGreeks()`

### 5. **SABRModel**
   - **Responsibilities**: Implements the SABR model functionalities.
   - **Methods**:
     - `calibrateParameters()`
     - `calculateImpliedVolatility()`
     - `generateVolatilitySurface()`

### 6. **VolatilitySurface**
   - **Responsibilities**: Manages the volatility surface construction and analysis.
   - **Methods**:
     - `constructSurface()`
     - `analyzeSurface()`
     - `plotSurface()`

### 7. **DataTypes (Utility)**
   - **Structs/Classes**:
     - Manages different types of data structures required.

## Sample Work Flow

1. **Read Data**: Using `FileReader` class to manage data reading and validation.
2. **PCP Check**: Applying `PCPChecker` for basic arbitrage opportunities.
3. **BSM Calculations**: Utilizing `BSMModel` for various calculations.
4. **Volatility Surface**: Managing volatility surface using `VolatilitySurface`.
5. **Advanced Models**:
   - Applying `HestonModel` and `SABRModel` for advanced model calculations.

Each step involves specialized classes and methods to execute specific functionalities and manage the required data efficiently. The modular design allows for easy modifications, updates, and scaling of the project.
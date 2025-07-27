

**Task**: Create a class called `Employee` with the following specifications:

### Attributes:
1. **Name**: A string that holds the name of the employee.
2. **Salary**: A numeric value (could be a `double`) representing the salary of the employee.

### Operations:
1. **Overload the `+` operator**: 
   - This operation should combine two `Employee` objects. Specifically, when two employees are combined using the `+` operator, their salaries should be added together, and their names should be concatenated.
   - The result should be a new `Employee` object with the combined name (e.g., "John & Jane") and the combined salary.
   
2. **Overload the `-` operator**:
   - This operation should compare the salaries of two `Employee` objects.
   - The comparison should return a statement about which employee has a higher salary or if they have the same salary.

### Objective:
- **Create the `Employee` class** with two attributes (`name` and `salary`).
- **Overload the `+` and `-` operators** to allow combining employees' information (name and salary) and comparing them based on their salary.
- Use **methods** to perform these operations instead of actual operator overloading, as Java doesn't support direct operator overloading.

### Example:

1. When you combine two `Employee` objects:
   - `Employee emp1 = new Employee("John", 50000);`
   - `Employee emp2 = new Employee("Jane", 60000);`
   - `Employee combined = emp1 + emp2;` 
     - This should create a new `Employee` object with name `"John & Jane"` and salary `110000`.

2. When you compare two `Employee` objects:
   - `String result = emp1 - emp2;`
     - This should output whether `emp1` has a higher salary than `emp2` or vice versa.

### Key Learning:
- **Operator Overloading**: Implementing the custom behavior of operators like `+` and `-`.
- **Class Design**: Creating a class with attributes and methods for specific functionality.
- **Comparing Objects**: Writing logic to compare attributes of objects (in this case, salaries).

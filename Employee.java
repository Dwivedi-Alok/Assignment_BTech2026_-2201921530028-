class Employee {
    private String name;
    private double salary;

    // Constructor to initialize name and salary
    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    // Getter methods
    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    // Overloading the + operator to combine salaries of two employees
    public static Employee operatorPlus(Employee e1, Employee e2) {
        double combinedSalary = e1.getSalary() + e2.getSalary();
        return new Employee(e1.getName() + " & " + e2.getName(), combinedSalary);
    }

    // Overloading the - operator to compare salaries of two employees
    public static String operatorMinus(Employee e1, Employee e2) {
        if (e1.getSalary() > e2.getSalary()) {
            return e1.getName() + " has a higher salary than " + e2.getName();
        } else if (e1.getSalary() < e2.getSalary()) {
            return e2.getName() + " has a higher salary than " + e1.getName();
        } else {
            return e1.getName() + " and " + e2.getName() + " have the same salary.";
        }
    }

  
    public static void main(String[] args) {
        Employee emp1 = new Employee("Alok", 50000);
        Employee emp2 = new Employee("Ankita", 60000);

        
        Employee combinedEmployee = Employee.operatorPlus(emp1, emp2);
        System.out.println("Combined Employee: " + combinedEmployee.getName() + " with Salary: " + combinedEmployee.getSalary());

       
        String comparisonResult = Employee.operatorMinus(emp1, emp2);
        System.out.println(comparisonResult);
    }
}

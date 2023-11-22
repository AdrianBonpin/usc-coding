const cors = require('cors')
const express = require('express')
const bodyParser = require('body-parser')
const mysql = require('mysql2/promise')

const app = express()
app.use(cors())

const port = process.env.PORT || 3000

app.use(bodyParser.urlencoded({ extended: true}))

app.use(bodyParser.json())

app.get('/', (req, res) => {
    res.res('Check node terminal!')
})

app.listen(port, () => {
    console.log(`Server listening on localhost:${port}`)
})

const pool = mysql.createPool({
    host: 'localhost',
    user: 'root',
    password: '',
    database: 'sampledb',
    waitForConnections: true,
    connectionLimit: 10,
    queueLimit: 0
})

// Function to create an entry
async function createEmployee(employeeData) {
    const connection = await pool.getConnection()
    try {
        const sql = 'INSERT INTO employees SET ?'
        const [result] = await connection.query(sql, employeeData)
        return result.insertId
    } finally {
        connection.release()
    }
}

// Function to get all entries
async function getAllEmployees() {
    const connection = await pool.getConnection()
    try {
        const [rows] = await connection.query('SELECT * FROM employees ORDER BY id DESC')
        return rows
    } finally {
        connection.release()
    }
}

// Function to get a single entry by ID
async function getEmployeeById(id) {
    const connection = await pool.getConnection()
    try {
        const [rows] = await connection.query('SELECT * FROM employees WHERE id = ?', [id])
        return rows[0]
    } finally {
        connection.release()
    }
}

// Function to update an entry by ID
async function updateEmployeeById(id, updatedData) {
    const connection = await pool.getConnection()
    try {
        const sql = 'UPDATE employees SET ? WHERE id = ?'
        await connection.query(sql, [updatedData, id])
        return true
    } finally {
        connection.release()
    }
}

// Function to delete an entry by ID
async function deleteEmployeeById(id) {
    const connection = await pool.getConnection()
    try {
        const sql = 'DELETE FROM employees WHERE id = ?'
        await connection.query(sql, [id])
        return true
    } finally {
        connection.release()
    }
}

async function test() {

    const emp0 = await createEmployee({
        first_name: "test",
        last_name: "tester",
        email: "test@example.com",
        phone: "123-456-7890",
        organization: "Test Corp",
        designation: "Tester",
        salary: 99999,
        status: 1,
        created_at: new Date(),
    })

    const emp1 = await createEmployee({
        first_name: "John",
        last_name: "Doe",
        email: "john@example.com",
        phone: "123-456-7890",
        organization: "XYZ Corp",
        designation: "Engineer",
        salary: 50000,
        status: 1,
        created_at: new Date(),
    })

    const emp2 = await createEmployee({
        first_name: "Adrian",
        last_name: "Bonpin",
        email: "adrianbonpin@gmail.com",
        phone: "0917-166-5863",
        organization: "linkHealth",
        designation: "Software Dev",
        salary: 50000,
        status: 1,
        created_at: new Date(),
    })

    // Get all employees
    const allEmployeesBeforeUpdate = await getAllEmployees()
    console.log('\n\n+ - - - - -\n| All Employees (Before Update):', allEmployeesBeforeUpdate)

    // Get a single employee by ID
    const emp1id = await getEmployeeById(emp1);
    console.log("\n\n+ - - - - -\n| Employee by ID:", emp1id);

    // Update an employee by ID
    await updateEmployeeById(emp1, { salary: 80000 });

    // Get all employees after update
    const allEmployeesAfterUpdate = await getAllEmployees();
    console.log('\n\n+ - - - - -\n| All Employees (After Update):', allEmployeesAfterUpdate);

    // Delete an employee by ID
    await deleteEmployeeById(emp1);
    await deleteEmployeeById(emp2);

    // Get all employees after deletion
    const allEmployeesAfterDelete = await getAllEmployees();
    console.log("\n\n+ - - - - -\n| All Employees (After Delete):", allEmployeesAfterDelete);
}

test().catch(console.error);
const cors = require('cors')
const express = require('express')
const bodyParser = require('body-parser')

const app = express()
app.use(cors())

const port = process.env.PORT || 3000

app.use(bodyParser.urlencoded({ extended: true}))

app.use(bodyParser.json())

app.get('/', (req, res) => {
    res.send("Hello Bonpin, Adrian Alfred")
})

app.listen(port, () => {
    console.log(`Server listening on localhost:${port}`)
})
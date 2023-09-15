const connectToMongo = require("./db")
const express = require('express')

connectToMongo();


const app = express()
const port = 3000

app.use(express.json())
app.use('/api/auth', require('./routes/auth'))
// app.use('/api/notes', require('./routes/notes'))

app.get('/yo', (req, res) => {
  res.send('Hello World!')
})
app.get('/yo/wo', (req, res) => {
  res.send('wo!')
})
app.get('/yo/wo/hoe', (req, res) => {
  res.send('hoe!')
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})
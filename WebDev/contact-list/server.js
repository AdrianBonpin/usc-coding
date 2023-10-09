const express = require('express');
const bodyParser = require('body-parser');
const Datastore = require('nedb');
const path = require('path');
const cors = require('cors');

const app = express();
const port = 4000; // Change this to your desired port

const db = new Datastore({ filename: "contacts.db", autoload: true });

app.use(cors());

app.use(bodyParser.json());

// Define API endpoints

// Get all contacts
app.get("/api/contacts", (req, res) => {
  db.find({}, (err, contacts) => {
    if (err) {
      res.status(500).json({ error: "Internal server error" });
    } else {
      res.json(contacts);
    }
  });
});

// Add a new contact
app.post("/api/contacts", (req, res) => {
  const newContact = req.body;
  db.insert(newContact, (err, contact) => {
    if (err) {
      res.status(500).json({ error: "Internal server error" });
    } else {
      res.status(201).json(contact);
    }
  });
});

// Delete a contact by ID
app.delete("/api/contacts/:id", (req, res) => {
    const contactId = req.params.id;
    db.remove({ _id: contactId }, {}, (err, numRemoved) => {
      if (err) {
        res.status(500).json({ error: "Internal server error" });
      } else if (numRemoved === 0) {
        res.status(404).json({ error: "Contact not found" });
      } else {
        res.sendStatus(204); // No Content
      }
    });
  });

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});

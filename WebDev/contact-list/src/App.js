import "./App.css";
import React, { useState, useEffect } from "react";
import axios from "axios"; // Import axios

axios.defaults.baseURL = "http://localhost:4000";

function App() {
  const [contacts, setContacts] = useState([]);
  const [lastName, setLastName] = useState("");
  const [firstName, setFirstName] = useState("");
  const [email, setEmail] = useState("");
  const [contactNumber, setContactNumber] = useState("");

  useEffect(() => {
    // Load contacts from the API when the component mounts
    axios
      .get("/api/contacts") // Use the API endpoint
      .then((response) => {
        setContacts(response.data);
      })
      .catch((error) => {
        console.error("Error loading contacts:", error);
      });
  }, []);

  const addContact = () => {
    if (lastName && firstName && email && contactNumber) {
      const newContact = {
        name: `${firstName} ${lastName}`,
        email,
        contactNumber,
      };

      // Make a POST request to add the contact
      axios
        .post("/api/contacts", newContact)
        .then((response) => {
          setContacts([...contacts, response.data]);
          setLastName("");
          setFirstName("");
          setEmail("");
          setContactNumber("");
        })
        .catch((error) => {
          console.error("Error adding contact:", error);
        });
    }
  };

  const deleteContact = (contact, index) => {
    // Make a DELETE request to remove the contact by its _id
    axios
      .delete(`/api/contacts/${contact._id}`)
      .then(() => {
        const updatedContacts = [...contacts];
        updatedContacts.splice(index, 1);
        setContacts(updatedContacts);
      })
      .catch((error) => {
        console.error("Error deleting contact:", error);
      });
  };

  return (
    <div>
      <div className="container">
        <div className="row">
          <label htmlFor="lname">Last Name</label>
          <input
            type="text"
            id="lname"
            value={lastName}
            onChange={(e) => setLastName(e.target.value)}
          />
        </div>
        <div className="row">
          <label htmlFor="fname">First Name</label>
          <input
            type="text"
            id="fname"
            value={firstName}
            onChange={(e) => setFirstName(e.target.value)}
          />
        </div>
        <div className="row">
          <label htmlFor="email">Email</label>
          <input
            type="email"
            id="email"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
          />
        </div>
        <div className="row">
          <label htmlFor="contact">Contact #</label>
          <input
            type="text"
            id="contact"
            value={contactNumber}
            onChange={(e) => setContactNumber(e.target.value)}
          />
        </div>
        <button onClick={addContact}>Add Contact</button>
      </div>
      <div className="container">
        <h1>CONTACTS</h1>
        <table id="main_table">
          <tr>
            <th>Name</th>
            <th>Email</th>
            <th>Contact</th>
            <th>Delete</th>
          </tr>
          {contacts.map((contact, index) => (
            <tr key={index}>
              <td>{contact.name}</td>
              <td>{contact.email}</td>
              <td>{contact.contactNumber}</td>
              <td>
                <button onClick={() => deleteContact(contact, index)}>
                  Delete
                </button>
              </td>
            </tr>
          ))}
        </table>
      </div>
    </div>
  );
}

export default App;

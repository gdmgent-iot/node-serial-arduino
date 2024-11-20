import express from "express";
import path from "path";
import bodyParser from "body-parser";
import { SerialPort } from "serialport";
import { ReadlineParser } from "@serialport/parser-readline";

// create a serial port
const arduinoPort = new SerialPort({
  path: "/dev/cu.usbmodem11202",
  baudRate: 9600,
});

// create an express app
const app = express();
const folderTemplate = path.resolve("templates");

// serve static files from the public directory
app.use(express.static("public"));
app.use(bodyParser.urlencoded({ extended: true }));

// serve the homepage
app.get("/", (req, res) => {
  res.sendFile(path.join(folderTemplate, "home.html"));
});

app.post("/draaien", (req, res) => {
  // hoek ophalen
  const angle = req.body.degrees;

  // send the angle to the Arduino
  arduinoPort.write(`${angle}\n`);

  // send a response to the client
  res.send(`Draaien naar ${angle} graden`);
});

// start the server
app.listen(3000, () => {
  console.log("Server started on http://localhost:3000");
});

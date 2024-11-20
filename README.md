# Servo Interface Application

This application provides a web interface to control a servo motor connected to an Arduino. It uses Express.js for the server, SerialPort for communication with the Arduino, and serves static files and templates for the web interface.

## Project Structure

servo-interface/
├── .gitignore
├── app.js
├── package.json
├── public/
│   └── ...
├── templates/
│   └── home.html
└── ...

## Setup Instructions

1. **Clone the Repository**:
    First, clone the repository to your local machine using the following command:

    ```bash
    git clone https://github.com/yourusername/servo-interface.git
    ```

2. **Navigate to the Project Directory**:
    Change your working directory to the project folder:

    ```bash
    cd servo-interface
    ```

3. **Install Node.js Dependencies**:
    Install the required Node.js packages using `npm`:

    ```bash
    npm install
    ```

4. **Connect the Arduino**:
    Ensure your Arduino is connected to your computer via USB and note the port it is connected to (e.g., `/dev/cu.usbmodem11202`).

5. **Update Serial Port Path**:
    In the `app.js` file, update the `path` property of the `SerialPort` configuration to match your Arduino's port:

    ```js
    const arduinoPort = new SerialPort({
      path: "/dev/cu.usbmodem11202", // Update this path
      baudRate: 9600,
    });
    ```

6. **Start the Server**:
    Start the Express.js server:

    ```bash
    npm start
    ```

7. **Access the Application**:
    Open your web browser and navigate to `http://localhost:3000` to view the application.

## Usage

- **Home Page**:
    The home page provides a form to input the desired angle for the servo motor. Submit the form to send the angle to the Arduino and control the servo motor.

## File Descriptions

- **app.js**: Main server file that sets up the Express.js server, handles routes, and communicates with the Arduino.
- **package.json**: Contains the project metadata and dependencies.
- **public/**: Directory for static files (e.g., CSS, JavaScript).
- **templates/**: Directory for HTML templates.

## Dependencies

- **express**: Web framework for Node.js.
- **path**: Node.js module for handling file paths.
- **body-parser**: Middleware for parsing request bodies.
- **serialport**: Library for serial communication with the Arduino.

## License

This project is licensed under the MIT License.
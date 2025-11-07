# Onket: A C++ Qt E-commerce Platform

Onket is a comprehensive, feature-rich e-commerce desktop application built from the ground up in C++. It simulates a complete online shopping experience, from user authentication to order processing, all managed through a custom graphical user interface (GUI) built with the Qt framework.

## 📸 Screenshots

*(**Note:** A README for a GUI application is most effective with visuals. I strongly recommend you take 2-3 screenshots of your application and insert them here. You can do this by dragging the images into the GitHub editor or linking to them.)*


_The main product browsing window, showing dynamically loaded items._


_The customer dashboard or a detailed product page with the Q&A system._

## ✨ Key Features

The platform is divided into three main functional areas, with distinct user roles and capabilities.

### 👤 User & Authentication
* **Role-Based Access:** The system supports three user levels (`Guest`, `Customer`, and `Admin`), each with different permissions and UI views.
* **Secure Authentication:** Full sign-up, login, and logout functionality.
* **Customer Dashboard:** A dedicated dashboard for customers to manage their personal information, update passwords, and add/remove shipping addresses.

### 🛒 E-commerce Core
* **Dynamic Product Catalog:** Products are loaded dynamically and can be sorted by price, discount, or popularity.
* **Product Search:** A live search bar filters product results in real-time.
* **Full Shopping Cart:** Users can add items, adjust quantities, and remove items from their `BasketView`.
* **Order Processing:** A complete checkout process that creates persistent `Order` objects and manages inventory.

### 🚀 Advanced Features
* **Product Comparison Engine:** A `CompareWidget` allows users to select multiple items for a side-by-side comparison of their properties (e.g., price, specs).
* **Interactive Content System:** A full user-generated content system for each product, including:
    * **Comments/Reviews:** Users can write detailed reviews with pros, cons, and star ratings.
    * **Q&A Forum:** Users can post questions (`Question`) and other users or admins can post answers (`Reply`).
    * **Like/Dislike:** All comments and replies can be upvoted or downvoted.
* **Admin Panel:** A separate `Dashboard` view for Admins to:
    * Manage product inventory (add stock, new items).
    * Define new product categories (`Type`) and sub-categories.
    * View all registered users and their order histories.

## 🛠️ Technical Stack

* **Core Language:** **C++11**
* **GUI Framework:** **Qt 5** (specifically Qt Widgets, Qt GUI, QIcon)
* **Data Persistence:** **File-Based Serialization**
    * **XML:** Used for structured, nested data like product comments and Q&A threads.
    * **CSV:** Used for flat, tabular data like `User`, `Good`, and `Order` records.
* **Development Tools:** **Qt Creator**, **Qt Designer** (for `.ui` files), and **qmake**.

## 🏛️ Architectural Highlights

This project was built with a focus on C++ best practices and scalable design.

* **Object-Oriented Design:** The core logic is built on clear object-oriented principles. For example, `User` serves as an abstract base class, with `Admin`, `Customer`, and `Guest` inheriting from it to provide polymorphic behavior.
* **MVC-like Separation:** The application separates data logic (models like `Good.h`, `User.h`) from the GUI (views like `GoodMainViewWidget.h`, `Dashboard.h`), allowing for cleaner, more maintainable code.
* **Custom Widget Factory:** The UI is not just built from standard Qt components but features a library of custom, reusable widgets (e.g., `GoodPreviewWidget`, `CommentListWidgetItem`, `CompareWidget`) to create a dynamic and consistent user experience.
* **File-Based Persistence Layer:** A custom data layer was engineered to serialize C++ objects (like `Order`, `Good`, `Comment`) into XML and CSV files, which effectively acts as a lightweight, local database.

## 🚀 Getting Started

To run this project, you will need a C++ compiler and the Qt 5 libraries.

### Prerequisites
* A C++11 (or newer) compatible compiler (e.g., GCC, Clang, MSVC)
* [Qt 5 (or newer)](https://www.qt.io/download) (The open-source Qt Creator IDE is the recommended way to build this project)

### Installation & Running
1.  Clone the repository:
    ```sh
    git clone [https://github.com/alex-abrehforoush/E-commerce-Desktop-Platform.git](https://github.com/alex-abrehforoush/E-commerce-Desktop-Platform.git)
    cd E-commerce-Desktop-Platform
    ```
2.  Open the `.pro` file in **Qt Creator**.
3.  Qt Creator will automatically detect your installed Qt "Kit" (compiler and Qt libraries). Click "Configure Project".
4.  Build and run the project by clicking the green "Run" button (or pressing `Ctrl+R`).

## 📈 Future Improvements
* **Migrate to SQL:** Replace the CSV/XML persistence layer with a relational database (like **SQLite** or **PostgreSQL**) to improve performance, scalability, and data integrity.
* **Client-Server Model:** Refactor the core logic into a separate backend server (e.g., a C++ REST API) and make the Qt application a true client.
* **Unit Testing:** Implement the **QTest** framework to create a robust unit testing suite for the core e-commerce and user logic.
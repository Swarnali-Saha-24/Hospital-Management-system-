/* ==========================================
   CITYCARE HOSPITAL MANAGEMENT SYSTEM
   SCRIPT.JS
========================================== */

// ======================
// Backend URL
// ======================

const API_URL = "https://cautious-eureka-777w4wqq5vr5crv5w-9090.app.github.dev/api/patient";

// ======================
// Active Navigation
// ======================

const navLinks = document.querySelectorAll("nav ul li a");

navLinks.forEach(link => {

    link.addEventListener("click", function () {

        navLinks.forEach(item => item.classList.remove("active"));
        this.classList.add("active");

    });

});

// ======================
// Sticky Header Shadow
// ======================

window.addEventListener("scroll", function () {

    const header = document.querySelector("header");

    if (header) {

        if (window.scrollY > 50) {

            header.style.boxShadow = "0 5px 20px rgba(0,0,0,.15)";

        } else {

            header.style.boxShadow = "0 3px 15px rgba(0,0,0,.08)";

        }

    }

});

// ======================
// Add Patient Form
// ======================

const patientForm = document.getElementById("patientForm");

if (patientForm) {

    patientForm.addEventListener("submit", async function (e) {

        e.preventDefault();

        const patient = {

            name: document.getElementById("patientName").value,
            age: document.getElementById("patientAge").value,
            gender: document.getElementById("patientGender").value,
            disease: document.getElementById("patientDisease").value,
            phone: document.getElementById("patientPhone").value,
            address: document.getElementById("patientAddress").value

        };

        try {

            const response = await fetch(API_URL, {

                method: "POST",

                headers: {

                    "Content-Type": "application/json"

                },

                body: JSON.stringify(patient)

            });

            const result = await response.json();

            alert(result.message);

            patientForm.reset();

        }
        catch (error) {

            alert("Cannot connect to C Backend.");
            console.error(error);

        }

    });

}

// ======================
// Card Animation
// ======================

const cards = document.querySelectorAll(".card, .doctor-card");

cards.forEach(card => {

    card.addEventListener("mouseenter", () => {

        card.style.transform = "translateY(-10px)";

    });

    card.addEventListener("mouseleave", () => {

        card.style.transform = "translateY(0px)";

    });

});

// ======================
// Scroll To Top Button
// ======================

const topButton = document.createElement("button");

topButton.innerHTML = "↑";
topButton.id = "topBtn";

document.body.appendChild(topButton);

topButton.style.position = "fixed";
topButton.style.bottom = "25px";
topButton.style.right = "25px";
topButton.style.width = "50px";
topButton.style.height = "50px";
topButton.style.border = "none";
topButton.style.borderRadius = "50%";
topButton.style.background = "#0d6efd";
topButton.style.color = "#fff";
topButton.style.fontSize = "22px";
topButton.style.cursor = "pointer";
topButton.style.display = "none";
topButton.style.boxShadow = "0 5px 15px rgba(0,0,0,.2)";
topButton.style.zIndex = "999";

window.addEventListener("scroll", function () {

    if (window.scrollY > 300) {

        topButton.style.display = "block";

    } else {

        topButton.style.display = "none";

    }

});

topButton.addEventListener("click", function () {

    window.scrollTo({

        top: 0,
        behavior: "smooth"

    });

});

console.log("CityCare Hospital Management System Loaded Successfully.");
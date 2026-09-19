# Smart-Hospital-Resource-Allocation-System

Modular C implementation of a menu-driven Smart Hospital Patient \& Resource Allocation System featuring parallel arrays, emergency triage sorting, bed matrix management, automated billing, and file handling.







\# Smart Hospital \& Resource Allocation System



A modular, menu-driven console application built in C for \*\*CSC 1012 – Introduction to Computer Programming\*\* (University of Sri Jayewardenepura). The system simulates patient intake, bed allocation, emergency triage sorting, and medical billing for a hospital, using parallel arrays throughout.



\## Features



\- \*\*Patient Registration\*\* – Collects patient title, name, age, triage level, specialty, and ward admission details, with full input validation (including protection against non-numeric input).

\- \*\*Bed Allocation\*\* – Assigns the first available bed in the chosen ward and tracks occupancy in a 2D bed status matrix.

\- \*\*Billing Engine\*\* – Calculates consultation fees, emergency surcharges, ward stay costs, age-based subsidies, and final payable amounts, then prints a formatted bill.

\- \*\*Waiting Time Estimation\*\* – Estimates queue wait time per specialty based on current queue length.

\- \*\*Priority Sorting\*\* – Lists registered patients in triage priority order (Critical → Urgent → Normal) using selection sort.

\- \*\*Performance Reports\*\* – Summarizes patient counts by triage level, total revenue and discounts, bed occupancy percentage per ward, and the highest-paying patient.

\- \*\*File Persistence (Bonus)\*\* – Bed occupancy is saved to `beds\_status.txt` on exit and restored on the next run; every finalized bill is appended to `patient\_records.txt` as a permanent log.



\## Project Structure



```

├── main.c        # Global data + main() menu loop

├── register.c    # Patient registration and input validation

├── billing.c     # Billing calculations and bill printing

├── bed.c         # Bed allocation and bed status display

├── report.c      # Priority sorting and performance reporting

├── fileio.c      # Save/load bed status, patient record logging

├── hospital.h    # Constants, extern declarations, function prototypes

└── \*.cbp         # Code::Blocks project file

```



\## Menu Options



1\. Register Patient

2\. Check Bed Status

3\. View Patients by Priority

4\. Generate Performance Report

5\. Exit



\## Data Structures



The system uses \*\*parallel arrays\*\* (no structs) throughout:



\- Fixed lookup tables for the 4 doctor specialties and 4 hospital wards.

\- `bedOccupancy\[4]\[20]` – a 2D matrix tracking bed availability per ward.

\- Patient records tracked across multiple parallel arrays (name, age, triage level, specialty, admission details, billing totals), all indexed by the same patient index.



\## How to Run



1\. Open `SmartHospitalSystem.cbp` in Code::Blocks.

2\. Build the project (`Ctrl+F9`).

3\. Run it (`F9`).

4\. Follow the on-screen menu to register patients, check bed status, and generate reports.



\## Assumptions



\- Maximum of 100 patients per run and 50 characters per name (not specified in the assignment; chosen as reasonable defaults).

\- The first available (lowest-numbered) bed in a ward is assigned on admission.

\- Patient age is validated to 0–120 years; days admitted must be a positive integer.



\## Author



Developed as an individual assignment for CSC 1012, BSc (General) Degree, University of Sri Jayewardenepura.


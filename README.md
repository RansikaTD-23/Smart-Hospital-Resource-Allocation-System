SMART HOSPITAL & RESOURCE ALLOCATION SYSTEM
=============================================

This is a simple console-based hospital management system built in C, made for my CSC 1012 (Introduction to Computer Programming) assignment at the University of Sri Jayewardenepura.

It lets you register patients, assign them beds, calculate their bills, and see reports, all through a menu in the terminal.


WHAT IT CAN DO
--------------
1. Register a patient - enter their title (Mr./Mrs./Miss), name, age, how urgent their case is, which specialty they need, and whether they're being admitted.
2. Bed allocation - if the patient is admitted, the system automatically finds and assigns the first free bed in that ward.
3. Automatic billing - calculates the consultation fee, emergency surcharge, ward cost, any age discount, and the final amount, then prints a proper bill.
4. Bed status - check how many beds are free or occupied in each ward.
5. Priority list - shows all patients sorted so the most critical ones appear first.
6. Performance report - shows total patients by urgency, total revenue, total discounts given, bed occupancy %, and who paid the most.
7. Saves data between runs - bed occupancy is saved to a file so it's remembered even if you close and reopen the program. Every bill is also logged permanently to a text file.


MENU
----
1. Register Patient
2. Check Bed Status
3. View Patients by Priority
4. Generate Performance Report
5. Exit

After most screens, it'll ask you to press Enter before going back to the menu, so you have time to read the results.


FILES IN THIS PROJECT
----------------------
main.c     - the main menu and the program's starting point
register.c - handles registering a new patient (also has a small helper function that checks if the user typed a valid number)
billing.c  - does all the billing math and prints the bill
bed.c      - handles assigning beds and showing bed status
report.c   - sorts patients by priority and builds the summary report
fileio.c   - saves/loads bed data and keeps a log of patient bills
hospital.h - shared constants and function declarations used by all the files above


HOW TO RUN IT
-------------
1. Open the .cbp file in Code::Blocks.
2. Build it (Ctrl+F9).
3. Run it (F9).
4. Use the menu to try it out.


A FEW NOTES / ASSUMPTIONS I MADE
---------------------------------
1. I set a max of 100 patients and 50 characters per name, since the assignment didn't specify exact numbers.
2. Beds are given out in order, whichever bed is free first gets assigned.
3. Only bed status and billing logs are saved permanently between runs (as the assignment asked for). The patient list, priority list, and report reset each time you restart the program, since that part wasn't required to be saved.
4. Age must be between 0-120, and days admitted must be a positive number, just basic sanity checks.


ABOUT
-----
Made individually for CSC 1012, BSc (General) Degree, first year, University of Sri Jayewardenepura.

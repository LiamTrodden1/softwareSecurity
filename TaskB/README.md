<<<<<<< HEAD
=======
# SoftwareSecurityLiamT

### Task B: Threat Modelling and SDLC

## Spoofing Identity:
# Problem 1 Insecure Session Cookies:
The cookies for a logged in user stores the account type and username in plain text. The session cookies od not expire.

This can cause issues because: 
    Attacker can edit the session cookies so their account type becomes an admin account which elevates their privileges. 
    Sessions not expiring means that if not logged out, the attacker has ample time a users session to impersonate them. This leads to failures in authentication and authorisation. 

To mitigate this issue:
    Implement secure session management through the use of secret keys. 
    Only send Cookies over HTTPS.
    use server side authentication and authorisation as well so that only the unique session ID is stored in the Cookies and the role and data is stored securely in the server.

During the SDLC lifecycle:
    In the planning stage establish requirements for secure session handling, and identity tokens.
    In the design stage consider worst cases to ensure the cookies are as resistant as possible to spoofing attacks.
    In  the testing stage, simulate varios spoofing attacks and forged cookies to ensure that the malicios sessions are rejected.

## Tampering with Data:
# Problem 1 Unauthorised listing edits:
When registering as a seller you can create products and edit the listing. By changing the URL http://127.0.0.1:5000/edit/ to a number other than your product e.g. http://127.0.0.1:5000/edit/1 you can edit listings that arent yours.

This is an issue because:
    Attackers can edit the listing for malicios purposes such as XSS through adding harmful scripts into the listing or to sabotage listings by making the price £1.00 for example which is impacts the appications integrity.

To mitigate this issue:
    use paraterised queires to ensure the users listing inputs are treated as text and not code.
    Implement validation checks to ensure the owner of the product is the only one who can edit the listing.

During the SDLC lifecycle:
    In the design phase create a principle of least privilege policy to ensure editing product listings is limited to the owner.
    In the developemnt stage, ensure server side authroisation is utilised for all operations of a listing.
    use unit testing to test all possible cases in which a listing can be invalidly modified.


## Repudiation:
# Problem 1 No Logging of Role Changes:
There are no logs to confirm who updated users role or timestamps. There is only records of the users current role in the database.

This is harmful because:
    A user could update their account to a seller and immediatley make fraudulent listings and claim it was not them or it was an error with the application and the admins can't prove the user intentionally pressed the become a seller button. This makes it impossible to escalate the issue meaning the business may have to pay for the damages incurred.

To mitigate this issue:
    Implement a logging system for user accounts which stores the IP Address, user, timestamp and role. This way the activity can be traced.
    Improve the verification process of becoming a seller so the request needs to be approved by an admin to ensure only legitamate sellers can sell.
    Implement two factor authentication when becoming a seller to ensure the it is the legitamate user trying to become a seller.

During the SDLC Lifecyle:
    In the requirements stage, ensure a logging system is incorporated.
    In the design stage plan the auditing architecture of the logs as well as ensure that the logs are read only so they can't be altered.
    In the testing phase, performs actions that would trigger a logging event to ensure the logs are accurate and being created properly.


## Information Disclosure:
# Problem 1 Passwords not Hashed in Database:
The users passwords are stored directly in the database as plain text with no hashing algorithm.

This is harmful because:
    If an attacker gains access to the database they have all users account information which they can use to impersonate the user or steal their information.
    This is a complete loss of confidentiality  and violates GDPR laws.

To mitigate this issue:
    Implement password hashing with a modern hashing algorithm like Bcrypt so the passwords can't be discovered.
    Also implement satling and pepering of the hashing lagorithm for a stronger encyption of the password.

During the SDLC Lifecylce:
    In the requirements stage, define the secure credentials requirement s all sensitive data must be encrypted.
    In the design phase, decide the hashing algorithm to use and review the database schema
    In the testing phase create sample entiries to ensure everytning is stored securely and correctly.


## Denial of Service:
# Problem 1 No Maximum Input Length:
When making a listing, there is no limit to the length the sellers description can be. this means that a harmful description large strings of data can be inputted to make the server crash from memory issues.

This is problematic because:
    An attacker can crash the website for all users which directly impacts the availabiltiy and integrity of the website.

To mitigate this issue:
    Implement strong input validation and ensure there is a character limits on user input fields.

In the SDLC Lifecycle:
    During the requirements phase, define capacity constraints for user inputs 
    In the testing stage perform fuzz testing and unit testing to ensure intentionally long strings are rejected.


## Elevation of Privilege:
# Problem 1 SQL Injection: 
If you use the SQL injection ' OR 1=1 -- in the login page, you gain access to the admin account.

This is problematic because, the admin account has extra permissions to a standard user account such as creating items. If an attacker gains access to this, they can perform content injection and create harmful product listings with redirects to harvest sensitive data from users or create fake phishing listings to take money from real customers.

To mitigate this issue use parameterised queries to prevent SQL injections and escape user inputs so that they can't be used malicioulsy and mistaken for SQL commands

During the SDLC this issue should be addresed in the design stage, by implemeting parameterised queries. This will then be tested and verified in the testing stage before deployment by using common SQL Injections that could be harmful.




# Problem

# Fix

# SDLC Integration



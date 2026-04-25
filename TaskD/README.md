### Task D Dynamic Analysis and Exploit Development

I have chose to use OWASP Zap because:
    It is a free open source dymanic analysis tool making it extremely accessible to use.
    OWASP Zap is easy to use in that it has automated scans and only needs the URL to be able to perform a scan.
    The AJAX Spider scan provides a mpre in depth scan that runs tests on components that are hidden behind actions and would usually be missed.
However:
    OWASP Zap is very sensitive and flags even the littlest things. This causes an overwhelming amount of low and informational flags which unecessarily bloats the reports and produces a high volume of false positive results.
    OWASP Zap can struggle to login to a system to perform the scan if it has complex multi factor authentication systems (but for this application this was not a problem)
    Due to the AJAX spider, the scan can take a long time to run and is resource intensive to run which may become problematic for large scale systems.

Alternatively I could have used Burp Suite because:
    It is considered the industry standard dynamic analysis tool
    It hasd a large volume of extensions making the tool very customisable to fit your specific needs
    Has a much lower false positive rate that OWASP ZAP
However:
    Burp suite is not free apart from the very limited community edition that does not have automatic scans available, or project saving. This makes it far less accessible.
    Burp Suite is far more complex to use and is not very begginner friendly.

With this in mind I have decided to exclusively use OWASP ZAP.

From the OWASP ZAP results, It can be seen that:
    The Most severe threat to the application are all SQL Injections. 
    An SQL injection is a malicios script that can manipulate the database through inserting SQL code into an input field which is then mistaken as code.
    The tool has detetcted potential SQL Injection vulnerability points for the username and passowrd inputs in the login and register pages. Despite teh low confidence, this is indeed a real vulnerability.

    The second biggest threat was an absence of anti CSRF-tokens. A CSRF token is hidden value submitted alongside cookies. The cookies identifies the users session and the token proves the actions came from the correct user. Without the tokens available, attackers can use your existing session to perform actions on your behalf. The anti CSRF-token ensures uses a unique value that can't be predicted to stop the attacker imperonation the user. 

    The next biggest threat was the absance of a Content Security Policy (CSP) header not being set. A CSP is a contains a list of approved external script sources. This helps prevent cross site scripting (XSS) attacks as attackers can't insert external scripts that aren't approved. By not having a CSP leaves the web app vulnerable to XSS attacks.

    Another medium level threat was the absence of an anti click jacking header. This measn that an attacker can embed the application within another application and therefore tricking the user into interacting with layeres UI components that aren't part of the real application so they can perform malicious activities.

    The remaining threats are all low level threats: Cookie without SameSite Attribute  and X-Content-Type-Options Header Missing which both fall under the the medium level attacks and are unnecessary bloat from OWASP ZAP. The X-Content-Type-Options Header Missing falls under the clickjacking category, Cookie without SameSite Attribute falls under the no anti CSRF category. 
    The last threat is Server Leaks Version Information via "Server" HTTP Response Header Field ,eaning that the attacker can find the server version to find specific vulnerabilities to that version however this is only a concern if that version has knon vulnerabilities.

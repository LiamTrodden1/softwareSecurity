# Task C: Automated Security Testing

For my CI/CD pipeline, I have used Bandit as my static analysis tool. 

This is because:
1. Im designing tests in python which bandit is compatible with. 
2. Bandit generates detailed reports about its findings including the security issues code and a description of what the issue is. As well as a severity and and confidence rating from low to high indicating how much of a problem the security is and how accurately it has been identified.
3. Bandit can easily be reconfigured and tailored to your needs for the specific project.
4. Bandit is very easy to integrate into projects making it an excellent tool to begin coding securely.

However:
1. Bandit is only a static analysis tool and therefore can't detetct run time issues in the project. This also makes it weaker at finding logic flaws in the application.
2. Bandit can potentially flag false positives when a security issue doesn't exist. This is because it cannot understand the context of a situation and just recognising patterns that are potentially harmful.

To test my application:
I have designed a .bandit config file and a yaml file to run the tests on a git push.

The .bandit config file adjusts the report of the bandit scan so that it only reports medium and high level security issues that it is medium to high confidence in. In practice, this will allow more time to be allocated to the more severe issues and help prevent too much time being wasted on flase positive issues or issues that aren't a problem. The bandit scan has been configured to be recursive so it scans all  subdirectories as well for a more in depth scan of the sytem, and it includes all files so that the whole system is scanned. In this case, all files that exist are important to be scanned but in a large scale system, some may be excluded as they will not have security flaws so excluding them can reduce the overall scan time.

The first issue that bandit detected was an SQL Injection (B608).

This means that bandit detected that the users input is assumed to be safe with no precautions allowing an input like ' OR 1=1-- for the username which would bypass the username check as True allowing an attacker to gain access to an account.

The second issue v=bandit detected was a hashing algorithm issue. 

The MD5 hashing algorithm has been used as opposed to a newer alternative like Bcrypt. This is an issue because MD5 is an outdated hashing algorithm that can easily be cracked using modern techniques like a rainbow table or brute force to crack the hashing algorithm.  

I have incorporated a false positive issue too. In the getNumber funtion, the random module has been used to retrieve a random number. In context this is not a security issue. However, the python random module can be a security risk as it is not truly random and can be predicted if used in a security context. Therefore, it was falsely reported as an issue.


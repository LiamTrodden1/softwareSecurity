### Task C Automated Security Testing

For this static analysis tool CI/CD pipeline, I have used 2 tools. Bandit and Semgrep.

This supports a defence in depth testing strategy as both tools provide distinct results to ensure maximum coverage of the system.

In generaly, static analysis tools are great for finding bugs in the code of an application. They are fast to run compared to dynmaic analysis tools, consitent with their findings and can easily be scaled with a project.

However, Static analysis do not have run time awareness of the application.This leads to a low detection of logic flaws, and a high false positive rate due to a lack of context awareness.

I have selected bandit because:
    It is specifically designed to find security issues in Python code. Which makes it easy to integrate and incorporate into this python - flask web apps.
    Bandit is east to configure so it can be custom tailored to the exact application you are using.
    It is open source and easily available to everyone.
    Bandit uses abstract syntax trees to understand understand the structure of the application which makes it great for analysing complex data structures. Therefore potentially finding more complex issues.
    Bandit is also easy to run allowing for quick scans that aren't time costly.

However:
    Bandit has a high false positive rate for 'secret keys' and often flags anything that slightly resembles a password or secret key as an issue.
    Bandit has weak taint analysis meaning that if data is passed across multiple functions it can lose track of the data potentially allowing an SQL Injection Vulnerability to pass through.
    Bandit is also weak at detecting vulnerabilities in code between multiple files. For instance, if a helper function is defined in a seperate file and used elsewhere, when checking the other code, the helper function won't be analysed at the same time potentially leading to an exploitable gap in the security.
    Bandit also only works with python so will not scan other files that aren't .py in the workspace which may miss potential vulnerabilities.

I have chosen Semgrep because:
    It is not limited to scanning only python files. this means that it gives a full stack static anaysis scan of the whole application.
    Semgrep uses pattern matching to try and detect logic errors in the application which provides an alternative method of finding vulnerabilities that is differnt to bandit.
    Semgrep is much better at taint analysis therefore it pairs well with supporting bandits weaknesses, this makes it strong at uncovering SQL Injection vulenrabilities.
    Semgrep is easy to customise allowing for an easy integration of rules like exclude ... which helps reduce the amount of false positives in the scan.

However:
    semgrep can often be too sensitive leading to a bloat of low severity issues that are actually false positives. This may lead to you missing the low severity issues that are a problem
    Semgrep also suffers with a lpw detetction rate of inter-file vulerabilities.
    Semgrep does not natively work with windows which can cause slight issues with compatibility with the tool.
    Semgrep is not great at analysing complect datastructures unlike bandit. 

Results:
Bandit detected 18 issues with 1 being low severity, 16 being medium severity and 1 being high severity. The confidence of these issues is 14 with low confidence and 4 with medium confidence.
Semgrep detected 92 issues with all of them being high severity.
This suggests that semgreps pattern matching algorithm was more beneficial at detecting the majority of the applications issues. This is further backed up by the fact that the majority of the issues are SQL injection related which Semgrep excells at. However, Bandit was more effective at discovering insecure configurations than Semgrep.

Both tools mainly detected potential SQL injection however, Bandit consistently had a much lower confidence level in its findings between low and medium where as Semgrep had high confidence in each of its SQL findings.

Both tools detected the weak MD5 hashign algorithm but again Semgrep was more confident in this finding than Bandit.

Due to Bandit being native to python it was able to detect that debug mode is enabled allowing attackers to execute code on the application. This is a high severity issue that Semgrep did not detect.

Bandit detected a hardcoded secret which woudl ussually be an issue for a real world application however in this case it is fine as the application is only local therefore it can be deduced as a false positive.

Semgrep flagged the same issue multiple times in some cases leading to redundant results that bloat the results wit false positives.

Semgrep was able to detect a cookies security issue as the cookies are sent over HTTP and not HTTPS.




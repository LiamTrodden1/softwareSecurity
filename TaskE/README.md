### Task E: Compliance and Exploit Development

I have first generated a requirements.txt file using the command "pip freeze > requirements.txt"

I have then used cyclonedx-bom to make a more detailed requiremnts form using PURLs (Package URLs) in a JSON format. 
This tool adds the exact versions of the librares used and their dependencies for a more detailed Software Bill Of Materials (SBOM).

The NIST SSDF is a global standard for secure software development. It contains 4 pillars to ensure secure software development which are: PO (Prepare the Organisation), PS (Protect the Software), PW(Produce Well secured software), and RV (Respond to Vulnerability). 

PO - This involves implementing corporate policies and staff training.

PS - This involves integrating security between developed code and its deployment. In order to achieve this, all components involved in the software developemnt should be secured from unauthorised access to help prevent security breaches and tampering. This is acheived through a locked git branches to prevent accidental pushes to the main branch and CI/CD automation to prevent human error in the production server as well as achieve predictable outputs.

PW - This pillar focuses on produces software with the least amount of vulnerabilities possible. This involves generating artifacts such as a Software Bill of Materials (SBOM) and automated scan results such as OWASP ZAP logs for dynamic analysis and Semgrep results for Static analysis. 

RV - This pillar aims to identify and correct vulnerabilities as they occur to maintain a secure software application. 

Overall, this framework helps bridge the gap between business owners and the developement team as well as helping to integrate the industry standards and best practices for secure development.

A software Bill of Materials helps to maintain compliance with the NIST Secure Software Developement because:
    An SBOM supports transparancy and integrity through ensuring all third party components are listed and identified, which helps the business identify if the libraries are secure. This supports the PW pillar.

    Furthermore, by providing versions of the external versions of the library, auditors can prove the security of the software if a problem should occur between building and deploying the software. This supports the PS Pillar.

    Since the SBOM itself is machine readable, it can be used to check for vulnerabilities in the versions of libraries that have been used which supports the RV pillar. 





p

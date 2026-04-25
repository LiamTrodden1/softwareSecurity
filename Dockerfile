FROM python:3.9-slim

RUN useradd -m secureuser

WORKDIR /app

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY . .

RUN chown -R secureuser:secureuser /app

USER secureuser

EXPOSE 8080

CMD ["python", "app.py"]

SSL_DIR = ssl
KEY = $(addprefix $(SSL_DIR)/, nginx.key)
CRT = $(addprefix $(SSL_DIR)/, nginx.crt)

keys:
	mkdir -p ssl
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-subj /C=KR/ST=Seoul/L=Seoul/O=42/OU=Lee/CN=nginxsvc \
	-keyout $(KEY) -out $(CRT)

clean:
	rm -f $(KEY)
	rm -f $(CRT)

.PHONY: keys clean

import socket

sock = socket.socket(
                        socket.AF_INET,
                        socket.SOCK_STREAM,
                        proto=0)


sock.bind(('localhost', 9090))
sock.listen(10)

client_sock, client_addr = sock.accept()

while True:
    data = client_sock.recv(1024)
    if not data:
        break
    client_sock.sendall(data * 2)

client_sock.close()
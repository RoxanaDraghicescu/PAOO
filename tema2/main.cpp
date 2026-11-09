#include <iostream>
#include <string>

class SmartSensor {
private:
    const std::string sensorId; 
    std::string location;
    double threshold;
    int readingCount;

public:
    // Member Initialization List - ordinea din lista respecta ordinea declararii in clasa
    SmartSensor(const std::string& id, const std::string& loc, double th)
        : sensorId(id), 
          location(loc), 
          threshold(th), 
          readingCount(0) 
    {
        std::cout << "SmartSensor " << sensorId << " creat cu succes\n";
    }

    void display() const {
        std::cout << "Senzor ID: " << sensorId << ", Locatie: " << location 
                  << ", Prag: " << threshold << ", Citiri: " << readingCount << "\n";
    }
};

// ex pt evitarea problemelor de init a obiectelor statice non-locale 
class SystemConfig {
private:
    SystemConfig() {
        std::cout << "SystemConfig initializat\n";
    }
public:
    static SystemConfig& getInstance() {
        static SystemConfig instance;  // Obiect static local: se creeaza doar la primul apel
        return instance;
    }
    void showStatus() const {
        std::cout << "SystemConfig este activ\n";
    }
};


class NetworkNode {
private:
    const std::string ipAddress; // impiedica generarea implicita a operatorului =
    int port;

public:  
    NetworkNode(const std::string& ip, int p) : ipAddress(ip), port(p) {
        std::cout << "NetworkNode creat pentru IP: " << ipAddress << "\n";
    }

    // Constructor de copiere
    NetworkNode(const NetworkNode& other) : ipAddress(other.ipAddress), port(other.port) {
        std::cout << "Constructorul de copiere a fost apelat\n";
    }

    // Daca am incerca node1 = node2, am obtine o eroare de compilare

    void display() const {
        std::cout << " Nod retea - IP: " << ipAddress << ", Port: " << port << "\n";
    }
};


class SecurityCamera {
private:
    int cameraId;
    std::string streamUrl;

public:
    SecurityCamera(int id, const std::string& url) : cameraId(id), streamUrl(url) {
        std::cout << "SecurityCamera " << cameraId << " instalata\n";
    }

    // O security camera este unica, copierea ei nu are sens in aplicatie. Interzicem copierea folosind delete
    SecurityCamera(const SecurityCamera&) = delete;
    SecurityCamera& operator=(const SecurityCamera&) = delete;

    void display() const {
        std::cout << "SecurityCamera ID " << cameraId << ", URL: " << streamUrl << "\n";
    }
};


int main() {
    std::cout << "--ITEM 4\n";
    SmartSensor tempSensor("SNSR-001", "Living", 23.5);
    tempSensor.display();

    SystemConfig& config = SystemConfig::getInstance();
    config.showStatus();

    std::cout << "\n--ITEM 5\n";
    NetworkNode nodeA("192.168.1.10", 8080);
    // Constructorul de copiere(init unui obiect nou)
    NetworkNode nodeB = nodeA; 
    nodeB.display();
    // nodeA = nodeB ar genera eroare de compilare deoarece ipAddress este const si nu se genereaza un operator de atribuire valid

    std::cout << "\n--ITEM 6\n";
    SecurityCamera cam1(101, "rtsp://192.168.1.50/stream");
    cam1.display();
    // SecurityCamera cam2 = cam1; // Eroare: folosirea unei functii sterse 

    return 0;
}
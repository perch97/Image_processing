#include <iostream>
#include <stdexcept>
#include <exception>
struct SpeedUpdate{
    double velocity_mps;
};

struct CarDetected{
    double distance_m;
    double velocity_mps;
};

struct BrakeCommand{
    double time_to_collision_s;
};

struct ServiceBus{
    void publish(const BrakeCommand&);
};

template <typename T>
struct AutoBrake{
//The AutoBrake class has a single constructor 
//that takes the template parameter publish
    AutoBrake(const T& publish)
    : collision_threshold_s{5},
      speed_mps{}, 
      publish{publish}{}; 

    void observe(const SpeedUpdate&){};
    void observe(const CarDetected&){};
    void set_collision_threshold_s(double x){
         if(x<1) throw std::exception{"Collision less than 1."};
         collision_threshold_s = x;}
    

   
    //getter
    double get_collision_threshold_s() const{
        return collision_threshold_s;
    };
    //getter to make speed_mps a public member
    double get_speed_mps() const{
        return speed_mps;
    };
private:
    double collision_threshold_s;
    double speed_mps;
    const T& publish;

};

//A unit test’s most essential component is the assertion, 
//which checks that some condition is met. 
//If the condition isn’t met, the enclosing test fails.
constexpr void assert_that(bool statement,const char* message){
    if(!statement) throw std::runtime_error{ message };
}

void initial_speed_is_zero(){
    AutoBrake auto_brake{ [](const BrakeCommand&) {}};
    assert_that(auto_brake.get_speed_mps()==0L, "speed not equal 0");
}

void initial_sensitivity_is_five(){
    AutoBrake auto_brake{ [](const BrakeCommand&) {}};
    assert_that(auto_brake.get_collision_threshold_s()==5L, "sensitivity is not 5");
}

void sensitivity_greater_than_1(){
    AutoBrake auto_brake{ [](const BrakeCommand&) {}};
    try{
        auto_brake.set_collision_threshold_s(0.5L);
    }catch(const std::exception&){
        return;
    }
    assert_that(false,"no exception thrown");
}

void run_test(void(*unit_test)(),const char* name){
    try{
        unit_test();
        printf("[+] Test %s successful. \n",name);
        } catch(const std::exception& e){
            printf("[-] Test failure in %s. %s. \n",name, e.what());
        }
}


int main(){
    run_test(initial_speed_is_zero,"initial speed is 0");
    run_test(initial_sensitivity_is_five,"initial sensitivity is 5");
    run_test(sensitivity_greater_than_1,"sensitivity grater than 1");
    ServiceBus bus;
    AutoBrake auto_brake{[&bus](const auto& cmd){
        bus.publish(cmd);
    }
    };
    while(true){//Service bus's event loop}
        auto_brake.observe(SpeedUpdate{10L});
        auto_brake.observe(CarDetected{250L,25L});
    }
}



class CarModule {
  constructor(speed) {
    let milesDriven = 0;
    speed = speed;

    this.accelerate = (amount) => {
      speed += amount;
      milesDriven += speed;
    }

    this.getMilesDriven = () => milesDriven;
  }
}

const testCarModule = new CarModule(100);
testCarModule.accelerate(5);
testCarModule.accelerate(4);
console.log(testCarModule.getMilesDriven());
console.log(testCarModule.speed);
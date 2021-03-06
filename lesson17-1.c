
let A = ["A","B","C","D","E","F","G","H","J","K"]
let A1 = ["_","A","B","C","D","E","F","G","H","J","K","_"]
let B: [Int] = [1,2,3,4,5,6,7,8,9,10]
//let B1: [Int] = [0,1,2,3,4,5,6,7,8,9,10,11]
let HL: [Int] = [1,2,3,4]
class Ship{
    let number: Int
    let x: String  
    let y: Int
    let l: Int
    let h: Int
    var countShot: Int
    
    enum ConditionShip{
        case healt
        case inj
        case kill
    } 

    init(x: String, y: Int, l: Int, h: Int, number: Int){
        self.countShot = 0
        self.number = number
        if A.contains(x){
               self.x = x
        }
        else{
            self.x = "Error"
            print(" x=Error")
        }    
        
        if B.contains(y){
            self.y = y}
        else{
            self.y = 0
            print(" Error x=0")
        }
        self.h = HL.contains(h) ? h : 1
        self.l = HL.contains(l) ? l : 1
    }
    var condShip: Ship.ConditionShip {
        get{ 
            switch self.countShot{
                case 0: return Ship.ConditionShip.healt
                case 1..<self.l * self.h: return ConditionShip.inj
                default: return Ship.ConditionShip.kill
            }
        }  
    }    
} 
class Field{
    var cell: [String: ConditionCell] = [:]
    var cond: [String: Ship] = [:]
    enum ConditionCell: String{
        case empty = "📉"
        case healt = "💹" 
        case inj = "📅"
        case rep = "💾"
    }
    subscript(_ s: String) -> (Field.ConditionCell){
        get{
            if let st = self.cell[s]{
                 return st
            }
            else{
                return ConditionCell.empty
            }    
        }
        
        set{
            if let cond = self.cell[s]{
                switch cond{
                case Field.ConditionCell.rep:
                    print("repit at nil");
                    break
                case Field.ConditionCell.inj:
                    print("repit at inj or kill");
                    break
                case Field.ConditionCell.healt where self.cond[s]!.condShip != Ship.ConditionShip.kill:
                    self.cell[s]! = Field.ConditionCell.inj;
                    self.cond[s]!.countShot += 1;
                    print("popal at \(self.cond[s]!.h * self.cond[s]!.l) klass ship");
                    if self.cond[s]!.condShip == kill {print("kill")} 
                default: break
                }
             }   
             else{
                 print("!!!!!!!!!!! Nil")
             }    

        }
    }    
}

var cells = Field()
var ship1 = Ship(x: "F", y: 5, l: 1, h: 2, number: 1)
var ship2 = Ship(x: "E", y: 4, l: 1, h: 1, number: 2)
var ship3 = Ship(x: "H", y: 5, l: 3, h: 1, number: 3)
var ships:[Ship] = [ship1,ship2,ship3]

func check(c: Field, x: String, y: Int, ship: Ship) -> Bool{
    var b: Bool
    for i in -1...1{
        for j in -1...1{ //print("ship\(ship.number) a: \(A1[A1.index(of: x )! + i]),    b:\(y + j)" )
            if let celll = c.cond["\(A1[A1.index(of: x )! + i])\(String(y + j))"]{
                if celll !== ship{
                     print("ship\(celll.number) slammed ship\(ship.number) and ship\(ship.number) will not by steped ")
                     return false
                     break
                }
             }
        }
    }
    return true
}              
    
for ship in ships{
    for h in 0...ship.h - 1{
        for l in 0...ship.l - 1{       
             if check(c: cells, x: A[A.index(of: ship.x)! + l] , y: ship.y + h, ship: ship){
               cells.cell["\(A[A.index(of: ship.x)! + l])\(ship.y + h)"] = Field.ConditionCell.healt
               cells.cond["\(A[A.index(of: ship.x)! + l])\(ship.y + h)"] = ship
                //print("tuye", ship.number )
             }
            else{
                //print("false")
            }   
        }
    }  
}



func out(){
    print("    A"," B"," C","  D"," E", "  F"," G"," H"," J","  K")
    for j in (1...10).reversed(){
        if j < 10 {print(terminator: " \(j)")}
        else{print(terminator: "\(j)")}
        for i in A{
            if let str = cells.cell["\(i)\( String(j))"]{
                   print(terminator: " \(str.rawValue)")
            }    
            else{
                   print(terminator:" \(Field.ConditionCell.empty.rawValue)")
            }    
        }
        print()
    }
}

                 
                
            
             /* if let cond = self.cell[s]{
                  if cond == Field.ConditionCell.rep || cond == Field.ConditionCell.inj{ 
                      print("repit")
                      break
                  }
                  else if let ship = self.cond[s]{
                             ship.countShot += 1
                             self.cell[s] = Field.ConditionCell.inj
                             print("popal")
                             if ship.condShip == Ship.ConditionShip.kill{ print("kill")} 
                      }
                      else{
                             self.cell[s] = Field.ConditionCell.rep
                             print("mimo")  
                      }
               }    
             }
            */     
out()
//print(cells["F8"])
//print(cells["F10"])
//cells["F10"] = Field.ConditionCell.shot
//print(cells["F10"].rawValue)
//cells["F6"] = Field.ConditionCell.shot
//out()
//cells["F5"] = Field.ConditionCell.shot
//out()
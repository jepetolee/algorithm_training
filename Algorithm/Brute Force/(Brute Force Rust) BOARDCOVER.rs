use std::io;

fn hasword(y:usize,x:usize,word:&mut Vec<char>,boardcover:&Vec<Vec<char>>) -> bool{
    let dx:Vec<isize> = vec![-1,-1,-1,1,1,1,0,0];
    let dy:Vec<isize> = vec![-1,0,1,-1,0,1,-1,1];
    if y >= 5 || x >= 5 {
        return  false;
    }
    if boardcover[y][x] != word[0] {
        return  false;
    }
    if word.len() ==1 {
         return  true;
    }

    word.remove(0);
    for direction in 1..8{
        let  next_x;
        let  next_y;
        match dx[direction] {
            -1 => next_x = x,
            _=> next_x =x+dx[direction] as usize,
        }
        match dy[direction] {
            -1 => next_y = y,
            _ => next_y = x + dy[direction] as usize
        }
       if next_x ==x && next_y ==y {

       }
        else{
        if hasword(next_y, next_x, word, &boardcover) {
            return true;
        }
            }
    }

    return false
}
fn main() {
    let  mut board = vec![vec!['\0';5];5];

    let mut test_case =String::new();

    io::stdin().read_line(&mut test_case).unwrap();
    let mut test_case:usize =test_case.trim().parse().unwrap();

    while test_case>0{
        test_case = test_case-1;
        //save the board
        for j in 0..5{
                let mut c = String::new();
                io::stdin().read_line(&mut c).unwrap();
                let mut c = c.split_whitespace();
            for k in 0..5{
                match  c.next().unwrap().chars().next(){
                    Some(t)=>board[j][k]=t,
                    None =>{}
                }
            }
        }
        let mut word =String::new();
        io::stdin().read_line(&mut word).unwrap();
        let mut word:Vec<char> = word.trim().chars().collect::<Vec<_>>();
        let mut result:bool =false;

        for i in 0..5 {
            for j in 0..5 {
                result = hasword(i, j, &mut word, &board);
                if result == true {
                    break;
                }
            }
        }
        println!("결과는...:{}",result);
    }
}
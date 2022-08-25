import React, { useEffect, useRef, useState } from 'react';
import './App.css';
import BananaLogo from './784c02c17fd3243b47bbbec9b08c90cb.png'
import PhoneScreen from './124da379beb443bfa1d54a460a494be3.jpg'
import useInterval from './useinterval';
import { reduceEachLeadingCommentRange } from 'typescript';
import { time } from 'console';

const canvasX = 1000;
const canvasY = 1000;
const initialSnake = [[4, 10], [4, 10]]
const initialBanana = [14, 10]
const scale = 50
const timeDelay = 100



function App() {
  //useState to store changing variables within the game
  const canvasRef = useRef<HTMLCanvasElement|null>(null)
  const [snake, setSnake] = useState(initialSnake)
  const [banana, setBanana] = useState(initialBanana)
  const [direction, setDirection] = useState([0, -1])
  const [delay, setDelay] = useState<number | null>(null)
  const [gameOver, setGameOver] = useState(false)
  const [score, setScore] = useState(0)
  
  useInterval(()=> runGame(),delay)

  useEffect(()=>{
    let fruit=document.getElementById("fruit") as HTMLCanvasElement
    if(canvasRef.current){
      const canvas = canvasRef.current
      const ctx=canvas.getContext("2d")
      if(ctx)
      {
        ctx.setTransform(scale,0,0,scale,0,0)
        ctx.clearRect(0,0, window.innerWidth, window.innerHeight)
        ctx.fillStyle="#800000"
        snake.forEach(([x,y])=>ctx.fillRect(x,y,1,1))    
        ctx.drawImage(fruit,banana[0],banana[1],1,1)
      }
    }
  }, [snake,banana,gameOver])

  function handleSetScore()
  {
    if(score>Number(localStorage.getItem("snakeScore")))
    {
      localStorage.setItem("SnakeScore",JSON.stringify(score))
    }

  }



  function play()
  {
    setSnake(initialSnake)
    setBanana(initialBanana)
    setDirection([1,0])
    setDelay(timeDelay)
    setScore(0)
    setGameOver(false)
  }

  function checkCollision(head:number[]){
    for(let i=0;i<head.length;i++ )
    {
      //if snake goes beyond border
      if(head[i]<0||head[i]*scale>=canvasX)return true
    }
    for(const s of snake)
    {
      //if snake hits itself
      if(head[0]===s[0]&&head[1]===s[1])return true
    }
    //otherwise continue game
    return false
  }


  function bananaAte(newSnake:number[][])
  {
    //gives apple random coordinates
    let coord=banana.map(()=>Math.floor(Math.random()*canvasX/scale))
    if(newSnake[0][0]===banana[0]&&newSnake[0][1]===banana[1]){
      //if eaten give apple new coordinates and give give user point
      let newBanana=coord
      setScore(score+1)
      setBanana(newBanana)
      return true
    }
    //otherwise apple doesnt move
    return false
  }

  function changeDirection(e:React.KeyboardEvent<HTMLDivElement>){
    switch(e.key){
      case "ArrowLeft":
        setDirection([-1,0])
        break;
        case "ArrowRight":
        setDirection([1,0])
        break;
        case "ArrowUp":
        setDirection([0,-1])
        break;
        case "ArrowDown":
        setDirection([0,1])
        break;
        
    }
  }



  function runGame(){
    const newSnake = [...snake]
    const newSnakeHead = [newSnake[0][0]+direction[0], newSnake[0][1]+direction[1]]
    newSnake.unshift(newSnakeHead)

    if(checkCollision(newSnakeHead)){
      setDelay(null)
      setGameOver(true)
      handleSetScore()
    } 
    if(!bananaAte(newSnake)){
      newSnake.pop()
    }
    setSnake(newSnake)
  }

  return (
    <div className="backgorund">
    <div onKeyDown={(e)=>changeDirection(e)}>
      <img id="fruit" src={BananaLogo} alt="fruit" width="30" />
      <canvas className='playArea' ref={canvasRef} width={`${canvasX}px`} height={`${canvasY}px`} style={{zIndex:9999}} />
      <ul>{gameOver && <div className='gameOver' color='#FB6200'>Game Over</div>}</ul>
      <button onClick={play} className="playButton">Play</button>
      <div className='scoreBox'>
        <h2>Score:{score}</h2>
        

      </div>

      <div className='titles'>
      <h1>EcoGif</h1>
    <h1>Snake</h1>
    </div>

    </div>
   
  </div>
  )
}

export default App;

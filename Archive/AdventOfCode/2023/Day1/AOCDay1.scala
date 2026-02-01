import scala.io.StdIn.readLine
import scala.io.Source

object AOCDay1 {
  def main(args: Array[String]): Unit = { 
    val filePath = "./input1"
    val source = Source.fromFile(filePath)
    var acum = 0L
    for( line <- source.getLines() ) { 
      val x = getNum(line)
      acum = acum + x
    }
    println(acum)
  }

  def getNum(line: String): Long = { 
    val numbers = line
      .filter(Character.isDigit)
      .mkString
    println(numbers)
    
    s"${numbers.head}${numbers.last}".toLong
  }
}

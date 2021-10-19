function combinations (s, n, letters) {
	if (s.length === n){
    a.push(s)
  }else{
    for (let x of letters){
      test(s + x, n, letters)
    }
  }
}

function generation(count){
	for (let i = 1; i <= count; i++){
		let data = generation_data_1(i)
		let text = generation_text_1(data)

		document.querySelector('.print-block').innerHTML += text
	}
}
function generation_data_1(){
	let symb = ['А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н',
	'О', 'П', 'Р', 'С', 'Т', 'У','Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я']
	let length = Math.floor(Math.random() * (6 - 3 + 1)) + 3
	let letters = []
	let count_letters = Math.floor(Math.random() * (6 - 3 + 1)) + 3
	for (let i = 1; i <= count_letters; i++){
		let x = Math.floor(Math.random()*symb.length)
		letters.push(symb[x])
		symb.splice(x, 1)
	}

	let place = Math.floor(Math.random() * (Math.pow(count_letters, length) - 4 + 1)) + 4
	let example = ""
	return {
		length: length,
		letters: letters,
		example: example,
		place: place
	}
}
function generation_answ_1(){

}
function generation_text_1(data){
	return `
		<div style="border: 2px solid #000; padding: 15px; background: #b9b9b9; margin-bottom: 15px;">
			Все ${data.length}-буквенные слова, составленные из букв ${data.letters} записаны в алфавитном порядке и пронумерованы. Вот начало списка:
			${data.example}
			……
			Запишите слово, которое стоит на ${data.place}-м месте от начала списка. 
		</div>
	`
}



document.querySelector('.form__button').addEventListener('click', e => {
	e.preventDefault()
	generation(document.querySelector('.form__input').value)	


})




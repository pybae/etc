require 'csv'
require 'erb'
require 'sunlight/congress'

Sunlight::Congress.api_key = "e179a6973728c4dd3fb1204283aaccb5"

def clean_zipcode(zipcode)
  zipcode.to_s.rjust(5, '0')[0..4]
end

def legislators_by_zipcode(zipcode)
  Sunlight::Congress::Legislator.by_zipcode(zipcode)
end

def save_thank_you_letter(id, letter)
  filename = "output/thanks_#{id}.html"
  
  File.open(filename, 'w') do |file|
    puts letter
  end
end

puts "EventManager Initialized!"

# opens the CSV file (ignoring the headers, and converting the indices of the headers into symbols)
contents = CSV.open("event_attendees.csv", headers: true, header_converters: :symbol)

template_letter = File.read("form_letter.erb")
erb_template = ERB.new(template_letter)

Dir.mkdir("output") unless Dir.exists?("output")

contents.each do |row|
  id = row[0]
  name = row[:first_name]

  zipcode = clean_zipcode(row[:zipcode])
  legislators = legislators_by_zipcode(zipcode)

  form_letter = erb_template.result(binding)
  
  save_thank_you_letter(id, form_letter)
end

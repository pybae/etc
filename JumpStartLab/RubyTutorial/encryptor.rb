class Encryptor
  def initialize(rotation)
    @rotation = rotation
    @cipher = generate_cipher(rotation)
    @decipher = @cipher.invert
  end

  def generate_cipher(rotation)
    key = (' '..'z').to_a
    value = key.rotate(rotation)
    Hash[key.zip(value)]
  end

  def encrypt_letter(letter)
    @cipher[letter.downcase]
  end

  def decrypt_letter(letter)
    @decipher[letter.downcase]
  end

  def encrypt(string)
    letters = string.split("")
    letters.collect { |c| encrypt_letter(c) }.join
  end

  def decrypt(string)
    letters = string.split("")
    letters.collect { |c| decrypt_letter(c) }.join
  end
end
